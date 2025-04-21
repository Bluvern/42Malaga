/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manualva <manualva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 09:51:16 by manualva          #+#    #+#             */
/*   Updated: 2025/03/25 11:16:18 by manualva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*
Inicializa los mutex para los tenedores que los filósofos necesitan para
comer, también inicializa un mutex para escribir y un mutex para comprobar
si todos los filósofos han comido. Si cualquiera de estos falla, envía un
error (1).
*/
int	init_mutex(t_rules *rules)
{
	int	i;

	i = rules->philo_num;
	while (--i >= 0)
	{
		if (pthread_mutex_init(&(rules->forks[i]), NULL))
			return (1);
	}
	if (pthread_mutex_init(&(rules->writing), NULL))
		return (1);
	if (pthread_mutex_init(&(rules->check_meal), NULL))
		return (1);
	return (0);
}

/*
Recorre los filósofos uno por uno usando philo->num y les asigna varios valores:
una ID única, cuántas veces ha comido, los tenedores que puede usar, el timestamp
de la última vez que comió, y un pointer a las reglas de la simulación.
*/
int	init_philo(t_rules *rules)
{
	int	i;

	i = rules->philo_num;
	while (--i >= 0)
	{
		rules->philosophers[i].id = i;
		rules->philosophers[i].x_ate = 0;
		rules->philosophers[i].left_fork_id = i;
		rules->philosophers[i].right_fork_id = (i + 1) % rules->philo_num;
		rules->philosophers[i].t_last_meal = 0;
		rules->philosophers[i].rules = rules;
	}
	return (0);
}

/*
Analiza los argv para dictaminar los valores de las reglas: el número de
filósofos, el tiempo que tienen para comer antes de morir, el tiempo que tardan
en comer, el que tardan en dormir, cuántas veces todos los filósofos han comido,
y si alguno de los filósofos ha muerto. Después comprueba que todos los valores
son válidos, y si lo son, asigna la cantidad de veces que tienen que comer para
finalizar la simulación (si es especificada). Finalmente inicia mutex y a los
filósofos y retorna 1 si hay algún problema con los input, 2 si hay un error en
el mutex, y 0 si se ha iniciado con éxito.
*/
int	init_all(t_rules *rules, char **argv)
{
	rules->philo_num = ft_atoi(argv[1]);
	rules->time_to_die = ft_atoi(argv[2]);
	rules->time_eating = ft_atoi(argv[3]);
	rules->time_sleeping = ft_atoi(argv[4]);
	rules->all_eaten = 0;
	rules->dead = 0;
	if (rules->time_to_die < MIN_TIME || rules->time_eating < MIN_TIME
		|| rules->time_sleeping < MIN_TIME || rules-> philo_num > PHILO_CAP)
		return (1);
	if (argv[5])
	{
		rules->n_eat = ft_atoi(argv[5]);
		if (rules->n_eat <= 0)
			return (1);
	}
	else
		rules->n_eat = -1;
	if (init_mutex(rules))
		return (2);
	init_philo(rules);
	return (0);
}
