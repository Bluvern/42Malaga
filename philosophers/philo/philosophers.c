/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manualva <manualva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 09:56:00 by manualva          #+#    #+#             */
/*   Updated: 2025/03/26 08:56:47 by manualva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_rules	rules;
	int		erret;

	if (argc != 5 && argc != 6)
		return (error_manager(3));
	erret = init_all(&rules, argv);
	if (erret)
		return (error_manager(erret));
	if (launcher(&rules))
		return (error_manager(4));
	return (0);
}
