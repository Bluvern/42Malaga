/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manualva <manualva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 09:15:00 by manualva          #+#    #+#             */
/*   Updated: 2025/03/25 11:13:47 by manualva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# ifndef PHILO_CAP
#  define PHILO_CAP 200
# endif

# ifndef MIN_TIME
#  define MIN_TIME 60
# endif

# include <sys/time.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>

typedef struct s_philo
{
	int				id;
	int				x_ate;
	int				left_fork_id;
	int				right_fork_id;
	long long		t_last_meal;
	struct s_rules	*rules;
	pthread_t		thread_id;
}	t_philo;
/*
id: El identificador del filósofo.
x_ate: Contador de cuántas veces ha comido un filósofo.
_fork_id: El identificador de cada tenedor.
t_last_meal: El tiempo desde la última comida. 
*rules: Un pointer que linkea al filósofo con las reglas.
thread_id: El identificador del thread de cada filósofo. 
*/

typedef struct s_rules
{
	int				philo_num;
	int				time_to_die;
	int				time_eating;
	int				time_sleeping;
	int				n_eat;
	int				dead;
	int				all_eaten;
	long long		first_timestamp;
	t_philo			philosophers[PHILO_CAP];
	pthread_mutex_t	check_meal;
	pthread_mutex_t	forks[PHILO_CAP];
	pthread_mutex_t	writing;
}	t_rules;
/*
philo_num: La cantidad de filósofos.
time_to_die: El tiempo que tienen para comer antes de morir de hambre.
time_eating: El tiempo que tardan en comer.
time_sleeping: El tiempo que duermen después de comer.
n_eat: Cuántas veces tiene que comer cada uno (opcional).
dead: Flag que se activa si un filósofo ha muerto.
all_eaten: Flag que se activa si todos los filósofos han comido la cantidad
requerida. 
first_timestamp: El tiempo en el que la simulación empieza.
philosophers[PHILO_CAP]: El array de los filósofos.
PHILO_CAP: El máximo de filósofos permitido. Por defecto es 200.
check_meal: Un mutex que protege el acceso de la acción de la comida.
forks[PHILO_CAP]: Un array de mutex representando los tenedores, para evitar
que más de un filósofo intente coger el mismo tenedor.
writing: Un mutex que protege la escritura, para evitar que se escriban varias
cosas a la vez.
*/

//Escribe un caracter en la terminal.
void		ft_putchar(char c);
//Convierte un string a int.
int			ft_atoi(const char *str);
//Obtiene el timestamp desde el Tiempo Unix en milisegundos.
long long	timestamp(void);
//Obtiene la diferencia de dos tiempos.
long long	timediff(long long past, long long present);
//Duerme el thread por intervalos de tiempo o hasta que un filósofo muere.
void		smart_sleep(long long time, t_rules *rules);
//Escribe la acción del filósofo junto al ID y el timestamp.
void		print_action(t_rules *rules, int id, char *str);
//Escribe el error encontrado.
int			write_error(char *str);
//Detecta cuál es el tipo de error.
int			error_manager(int error);
//Inicializa mutex, los filósofos, y asigna valores.
int			init_all(t_rules *rules, char **argv);
//Limpia los threads una vez el proceso ha terminado.
void		exit_launcher(t_rules *rules, t_philo *philo);
//Inicia la simulación y crea todos los threads requeridos.
int			launcher(t_rules *rules);

#endif