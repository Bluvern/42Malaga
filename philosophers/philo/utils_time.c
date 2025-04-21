/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manualva <manualva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 10:30:34 by manualva          #+#    #+#             */
/*   Updated: 2025/03/25 11:25:36 by manualva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*
Utiliza gettimeofday para conseguir el intervalo de tiempo actual, obtiene el
Tiempo Unix (tiempo desde el 1 de enero del 1970) y lo injerta en t, y 
retorna el tiempo desde el Tiempo Unix en milisegundos.
*/
long long	timestamp(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000) + t.tv_usec / 1000);
}

/*
Calcula la diferencia de tiempo entre dos timestamps.
*/
long long	timediff(long long past, long long present)
{
	return (present - past);
}

/*
Captura el timestamp y entra en un loop while en el que pone a dormir el thread
durante intervalos de tiempo. El loop termina si el intervalo de sueño ha acabado
o el filósofo ha muerto.
*/
void	smart_sleep(long long time, t_rules *rules)
{
	long long	i;

	i = timestamp();
	while (!(rules->dead))
	{
		if (timediff(i, timestamp()) >= time)
			break ;
		usleep(50);
	}
}
