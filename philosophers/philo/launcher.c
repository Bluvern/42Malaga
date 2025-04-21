/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launcher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manualva <manualva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 09:07:18 by manualva          #+#    #+#             */
/*   Updated: 2025/03/25 11:25:10 by manualva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*
Hace que un filósofo coma. Bloquea los tenedores que va a usar y el mutex de 
check_meal para actualizar el last_meal sin problemas, duerme el thread mientras 
el filósofo come y aumenta el contador de veces que ha comido, tras lo que 
libera los tenedores. Si solo hay un filósofo, agarra el tenedor y espera a
la muerte.
*/
void	eat(t_philo *philo)
{
	t_rules	*rules;

	rules = philo->rules;
	pthread_mutex_lock(&(rules->forks[philo->left_fork_id]));
	print_action(rules, philo->id, "has taken a fork.");
	if (rules->philo_num == 1)
	{
		smart_sleep(rules->time_to_die, rules);
		print_action(rules, philo->id, "died.");
		pthread_mutex_unlock(&(rules->forks[philo->left_fork_id]));
		rules->dead = 1;
		return ;
	}
	pthread_mutex_lock(&(rules->forks[philo->right_fork_id]));
	print_action(rules, philo->id, "has taken a fork.");
	pthread_mutex_lock(&(rules->check_meal));
	print_action(rules, philo->id, "is eating.");
	philo->t_last_meal = timestamp();
	pthread_mutex_unlock(&(rules->check_meal));
	smart_sleep(rules->time_eating, rules);
	philo->x_ate++;
	pthread_mutex_unlock(&(rules->forks[philo->left_fork_id]));
	pthread_mutex_unlock(&(rules->forks[philo->right_fork_id]));
}

/*
Simula el comportamiento de un filósofo en un thread aparte. Los filósofos pares
duermen muy brevemente para evitar problemas de superposición. Mientras no haya
filósofos muertos, el filósofo simula su rutina comiendo, durmiendo después de 
comer, y pensando por un periodo de tiempo. El ciclo se repite hasta que todos
los filósofos han comido las veces necesarias o alguno ha muerto.
*/
void	*p_thread(void *void_philo)
{
	int		i;
	t_philo	*philo;
	t_rules	*rules;

	i = 0;
	philo = (t_philo *) void_philo;
	rules = philo->rules;
	if (philo->id % 2)
		usleep(15000);
	while (!(rules->dead))
	{
		eat(philo);
		if (rules->all_eaten || rules->dead)
			break ;
		print_action(rules, philo->id, "is sleeping.");
		smart_sleep(rules->time_sleeping, rules);
		print_action(rules, philo->id, "is thinking.");
		i++;
	}
	return (NULL);
}

/*
Limpia los threads una vez el proceso ha terminado. Espera a que todos los 
threads de filósofos hayan terminado para unirlos, y una vez están todos 
unidos, destruye los mutex de los tenedores y el mutex de escritura.
*/
void	exit_launcher(t_rules *rules, t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < rules->philo_num)
		pthread_join(philo[i].thread_id, NULL);
	while (++i < rules->philo_num)
		pthread_mutex_destroy(&(rules->forks[i]));
	pthread_mutex_destroy(&(rules->writing));
}

/*
Se encarga de comprobar las condiciones de fin, ya sea que los filósofos hayan 
comido la cantidad necesaria de veces, o que alguno haya muerto. Corre 
paralelamente con las acciones de los filósofos y comprueba si alguno ha pasado 
demasiado tiempo sin comer. Loopea hasta que los filósofos han comido las veces 
necesarias o uno muere. Si alguno excede el time_to_die sin haber comido antes, 
marca el flag de muerte como positivo. Si todos los filósofos han terminado de
comer, marca el flag de comida como positivo.
*/
void	finish_checker(t_rules *r, t_philo *p)
{
	int	i;

	while (!r->all_eaten)
	{
		i = -1;
		while (++i < r->philo_num)
		{
			pthread_mutex_lock(&(r->check_meal));
			if (timediff(p[i].t_last_meal, timestamp()) > r->time_to_die)
			{
				print_action(r, i, "died.");
				r->dead = 1;
				pthread_mutex_unlock(&(r->check_meal));
				return ;
			}
			pthread_mutex_unlock(&(r->check_meal));
		}
		if (r-> dead)
			break ;
		i = 0;
		while (r->n_eat != -1 && i < r->philo_num && p[i].x_ate >= r->n_eat)
			i++;
		if (i == r->philo_num)
			r->all_eaten = 1;
	}
}

/*
Inicia la simulación y crea todos los threads requeridos. Empieza creando los
threads de los filósofos y comienza sus ciclos de comer, dormir y pensar. Acto
seguido, inicia el comprobador de finalización y una vez ha encontrado alguna
de las condiciones de fin, pasa el exit_launcher para limpiar los threads.
*/
int	launcher(t_rules *rules)
{
	int		i;
	t_philo	*philo;

	i = 0;
	philo = rules->philosophers;
	rules->first_timestamp = timestamp();
	while (i < rules->philo_num)
	{
		if (pthread_create(&(philo[i].thread_id), NULL, p_thread, &(philo[i])))
			return (1);
		philo[i].t_last_meal = timestamp();
		i++;
	}
	finish_checker(rules, rules->philosophers);
	exit_launcher(rules, philo);
	return (0);
}
