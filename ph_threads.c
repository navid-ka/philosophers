/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_threads.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkeyani- <nkeyani-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 00:11:52 by bifrost           #+#    #+#             */
/*   Updated: 2023/10/19 12:24:23 by nkeyani-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/philosophers.h"

static void	routine(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->dead_mutex);
	printf("%llu Philo[%d]\n", ph_time() - philo->table->start, philo->id);
	philo->table->is_dead = true;
	pthread_mutex_unlock(&philo->table->dead_mutex);
}

static void	ph_create_loop(t_table *data, t_philo *philo)
{
	uint64_t	i;

	i = 0;
	while (42)
	{
		pthread_mutex_lock(&data->dead_mutex);
		if (ph_time() - philo[i].last_meal >= data->time_to_die)
		{
			data->is_dead = true;
			pthread_mutex_unlock(&data->dead_mutex);
			break ;
		}
		pthread_mutex_unlock(&data->dead_mutex);
		i++;
		if (i == data->ph_num)
			i = 0;
	}
}
void	ph_create_philos(t_table *data, t_philo *philo)
{
	uint64_t	i;

	i = 0;
	data->start = ph_time();
	while (i < data->ph_num)
	{
		pthread_create(&data->philo[i].t, NULL, \
			(void *)routine, &data->philo[i]);
		i++;
		usleep(10);
	}
	usleep(10);
	ph_create_loop(data, philo);

	//pthread_join(data->philo[0].t, NULL);
	// usleep(100000);
}