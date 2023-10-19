/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_table_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkeyani- <nkeyani-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 20:51:28 by bifrost           #+#    #+#             */
/*   Updated: 2023/10/19 16:58:32 by nkeyani-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/philosophers.h"

int	ph_malloc_table(t_table *data)
{
	data->philo = malloc(sizeof(t_philo) * data->ph_num);
	if (!data->philo)
		return (printf("Malloc error.\n"), 0);
	return (1);
}

//TODO: Init philosophers logic
void	ph_init_philos(t_table *data)
{
	uint64_t	i;

	i = 0;
	pthread_mutex_unlock(&data->start_mutex);
	while (i < data->ph_num)
	{
		data->philo[i].id = i + 1;
		data->philo[i].r_fork = NULL;
		data->philo[i].last_meal = 0;
		pthread_mutex_init(&data->philo[i].l_fork, NULL);
		data->philo[i].table = data;
		i++;
	}
}
void	ph_create_philos(t_table *data)
{
	uint64_t	i;

	i = 0;
	data->start = ph_time();
	while (i < data->ph_num)
	{
		pthread_create(&data->philo[i].t, NULL, \
			(void *)routine, &data->philo[i]);
		i++;
	}
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
	pthread_mutex_init(&data->print_mutex, NULL);
	if (!ph_malloc_table(data))
		return (0);
	ph_init_philos(data);
	ph_create_philos(data);
	return (1);
}

