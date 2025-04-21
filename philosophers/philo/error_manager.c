/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manualva <manualva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 09:37:06 by manualva          #+#    #+#             */
/*   Updated: 2025/03/26 08:55:58 by manualva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	write_error(char *str)
{
	int	i;

	i = 0;
	write (2, "Error: ", 7);
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	ft_putchar('\n');
	return (1);
}

int	error_manager(int error)
{
	if (error == 1)
		return (write_error("Wrong argument values."));
	else if (error == 2)
		return (write_error("Couldn't initialize mutex."));
	else if (error == 3)
		return (write_error("Wrong amount of arguments."));
	else if (error == 4)
		return (write_error("Couldn't create threads."));
	return (1);
}
