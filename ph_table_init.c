/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_table_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkeyani- <nkeyani-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 20:51:28 by bifrost           #+#    #+#             */
/*   Updated: 2023/10/18 19:45:07 by nkeyani-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/philosophers.h"

int	ph_malloc_table(t_table *data)
{
	data->philo = malloc(sizeof(t_philo) * data->ph_num);
	if (!data->philo)
		return (write(1, "Malloc error.\n", 15), 0);
	return (1);
}

int	ph_init_table(t_table *data, char **argv)
{
	memset(data, 0, sizeof(*data));
	data->ph_num = ph_atoi(argv[1]);
	data->time_to_die = ph_atoi(argv[2]);
	data->time_to_eat = ph_atoi(argv[3]);
	data->time_to_sleep = ph_atoi(argv[4]);
	data->start = 0;
	pthread_mutex_init(&data->dead_mutex, NULL);
	if (!ph_malloc_table(data))
		return (0);
	return (1);
}

//TODO: Init philosophers logic
void	ph_init_philos(t_table *data)
{
	uint64_t	i;

	i = 0;
	while (i < data->ph_num)
	{
		data->philo[i].id = i + 1;
		data->philo[i].r_fork = NULL;
		data->philo[i].last_meal = 0;
		data->philo[i].table = data;
		pthread_mutex_init(&data->philo[i].l_fork, NULL);
		i++;
	}
}

void	routine(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->dead_mutex);
	printf("%lld Philo%d\n", ph_time() - philo->table->start, philo->id);
	philo->table->is_dead = true;
	pthread_mutex_unlock(&philo->table->dead_mutex);
}

void	ph_create_loop(t_table *data, t_philo *philo)
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
		pthread_create(&data->philo[i].t, NULL, (void *)routine, &data->philo[i]);
		i++;
		usleep(1000);
	}
	usleep(10);
	ph_create_loop(data, philo);

	//pthread_join(data->philo[0].t, NULL);
	// usleep(100000);
}
