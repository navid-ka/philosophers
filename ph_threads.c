/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_threads.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifrost <bifrost@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 00:11:52 by bifrost           #+#    #+#             */
/*   Updated: 2023/10/20 14:32:50 by bifrost          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/philosophers.h"

void	ph_eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->l_fork);
	ph_print(G, philo, FORK, false);
	pthread_mutex_lock(philo->r_fork);
	ph_print(R, philo, FORK, false);
	pthread_mutex_lock(&philo->time_die_mutex);
	philo->time_die =  philo->table->time_to_die + ph_time();
	pthread_mutex_unlock(&philo->time_die_mutex);
	ph_print(B, philo, EAT, false); // TODO: how many times it has eaten.
	ph_usleep(philo->table->time_to_eat);
	pthread_mutex_unlock(&philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
	ph_print(Y, philo, SLEEP, false);
	ph_usleep(philo->table->time_to_sleep);
	ph_print(O, philo, THINK, false);
	
}
void	routine(t_philo *philo)
{
	bool	ggwp;

	pthread_mutex_lock(&philo->table->start_mutex);
	pthread_mutex_unlock(&philo->table->start_mutex);
	if (philo->id % 2 == 0)
	{
		ph_usleep(philo->table->time_to_eat);
		pthread_mutex_lock(&philo->table->start_mutex);
		pthread_mutex_unlock(&philo->table->start_mutex);
	}
	ggwp = false;
	while (ggwp != true)
	{
		ph_eating(philo);
		pthread_mutex_lock(&philo->table->dead_mutex);
		ggwp = philo->table->is_dead;
		pthread_mutex_unlock(&philo->table->dead_mutex);
	}
}

void	control(t_table *data)
{
	uint64_t	i;
	uint64_t	time;

	i = 0;

	while (data->is_dead != true)
	{
		pthread_mutex_lock(&data->philo[i].time_die_mutex);
		time = data->philo[i].time_die;
		pthread_mutex_unlock(&data->philo[i].time_die_mutex);
		pthread_mutex_lock(&data->dead_mutex);
		if (ph_time() - data->start > time)
		{
			data->is_dead = true;
			pthread_mutex_unlock(&data->dead_mutex);
			ph_print(T, &data->philo[i], DEAD, true);
			break ;
		}
		pthread_mutex_unlock(&data->dead_mutex);
		i++;
		if (i == data->ph_num)
			i = 0;
		usleep(60);
	}
}
