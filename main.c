/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkeyani- <nkeyani-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 23:50:19 by bifrost           #+#    #+#             */
/*   Updated: 2023/10/24 16:30:29 by nkeyani-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/philosophers.h"

int	main(int argc, char **argv)
{
	t_table		data;
	t_philo		philo;
	uint64_t	i;

	memset(&data, 0, sizeof(data));
	memset(&philo, 0, sizeof(philo));
	if (!ph_args(argc, argv))
		return (printf("Arguments where not optimal\n"));
	if (!ph_init_table(&data, argv))
		return (EXIT_FAILURE);
	pthread_mutex_unlock(&data.start_mutex);
	control(&data);
	i = 0;
	while (i < data.ph_num)
		pthread_join(data.philo[i++].t, NULL);
	free(data.philo);
	return (EXIT_SUCCESS);
}
