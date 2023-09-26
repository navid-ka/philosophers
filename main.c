/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkeyani- < nkeyani-@student.42barcelona    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 23:50:19 by bifrost           #+#    #+#             */
/*   Updated: 2023/09/26 11:10:06 by nkeyani-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/philosophers.h"

int	main(int argc, char **argv)
{
	t_table	data;

	memset(&data, 0, sizeof(data));
	if (!ph_args(argc, argv))
		return (printf("Arguments where not optimal\n"));
	ph_init_table(&data, argv);
	ph_init_philos(&data);
	printf("ph_num : %lld\ntime_to_die : %lld\ntime_to_eat : %lld\ntime_to_sleep : %lld\n", \
		data.ph_num, data.time_to_die, data.time_to_eat, data.time_to_sleep);
	free(data.philo);
	exit(EXIT_SUCCESS);
}
