/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifrost <bifrost@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 23:50:19 by bifrost           #+#    #+#             */
/*   Updated: 2023/10/20 02:25:19 by bifrost          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/philosophers.h"

int	main(int argc, char **argv)
{
	t_table	data;
	t_philo	philo;

	memset(&data, 0, sizeof(data));
	memset(&philo, 0, sizeof(philo));
	if (!ph_args(argc, argv))
		return (printf("Arguments where not optimal\n"));
	if (!ph_init_table(&data, argv))
		return (EXIT_FAILURE);
	ph_usleep(100);
	pthread_mutex_unlock(&data.start_mutex);
	control(&data);
	free(data.philo);
	return (EXIT_SUCCESS);
}
