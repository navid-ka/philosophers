/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_threads.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkeyani- <nkeyani-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 00:11:52 by bifrost           #+#    #+#             */
/*   Updated: 2023/10/19 23:24:14 by nkeyani-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/philosophers.h"

void	ph_eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->l_fork);
	ph_print(G, philo, FORK, false);
	printf("entras?");
	pthread_mutex_lock(philo->r_fork);
	ph_print(G, philo, FORK, false);
	pthread_mutex_lock(&philo->time_die_mutex);
	philo->time_die = ph_time() + philo->table->time_to_die;
	pthread_mutex_unlock(&philo->time_die_mutex);
	ph_print(G, philo, EAT, false); // TODO: how many times it has eaten.
	ph_usleep(philo->table->time_to_eat);
	pthread_mutex_unlock(&philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
	ph_print(G, philo, SLEEP, false);
	ph_usleep(philo->table->time_to_sleep);
	ph_print(G, philo, THINK, false);
	
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
	while (ggwp != 1)
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

void	control(t_table *data, t_philo *philo)
{
	uint64_t	i;
	uint64_t	time;

	i = 0;
	pthread_mutex_lock(&data->philo[i].time_die_mutex);
		time = data->philo[i].time_die;
	pthread_mutex_unlock(&data->philo[i].time_die_mutex);
	while (42)
	{

		pthread_mutex_lock(&data->dead_mutex);
		if (ph_time() - philo[i].last_meal >= time)
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

/*void control(t_table *data, t_philo *philo)
{
	ph_create_loop(data, philo);
}*/