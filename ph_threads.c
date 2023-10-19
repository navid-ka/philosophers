/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_threads.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkeyani- <nkeyani-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 00:11:52 by bifrost           #+#    #+#             */
/*   Updated: 2023/10/19 19:24:04 by nkeyani-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/philosophers.h"

void	ph_eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->l_fork);
	ph_print(G, philo, FORK, false);
}
void	routine(t_philo *philo)
{
	bool	ggwp;

	pthread_mutex_lock(&philo->table->start_mutex);
	pthread_mutex_unlock(&philo->table->start_mutex);
	if (philo->id % 2 == 1)
	{
		ph_usleep(50);
		pthread_mutex_lock(&philo->table->start_mutex);
		pthread_mutex_unlock(&philo->table->start_mutex);
	}
	ggwp = 0;
	{
		ph_eating(philo);
		pthread_mutex_lock(&philo->table->dead_mutex);
		ggwp = philo->table->is_dead = true;
		pthread_mutex_unlock(&philo->table->dead_mutex);
	}
	//ph_print(R, philo, EAT, false);
	//printf("%llu Philo[%d]\n", ph_time() - philo->table->start, philo->id);
	//philo->table->is_dead = true;
	//pthread_mutex_unlock(&philo->table->dead_mutex);
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

void control(t_table *data, t_philo *philo)
{
	ph_create_loop(data, philo);
}