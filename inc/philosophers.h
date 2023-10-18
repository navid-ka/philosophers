/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkeyani- <nkeyani-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 23:50:26 by bifrost           #+#    #+#             */
/*   Updated: 2023/10/18 19:36:08 by nkeyani-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdbool.h>
# include <time.h>
# include <string.h>
# include <stdint.h>

//#define malloc(x) NULL

typedef struct s_philo
{
	struct s_table	*table;
	int				id;
	uint64_t		last_meal;
	pthread_t		t;
	pthread_mutex_t	ok;
	pthread_mutex_t	l_fork;
	pthread_mutex_t	*r_fork;
}	t_philo;

typedef struct s_table
{
	t_philo			*philo;
	uint64_t		ph_num;
	uint64_t		time_to_die;
	uint64_t		time_to_eat;
	uint64_t		time_to_sleep;
	uint64_t		time_to_start;
	uint64_t		meals;
	uint64_t		start;
	pthread_mutex_t	dead_mutex;
	bool		is_dead;
}	t_table;

// ph_parse.c

uint64_t	ph_atoi(char *s);
bool		ph_args(int argc, char **argv);

// ph_table_init.c

int			ph_init_table(t_table *data, char **argv);
int			ph_init_forks(t_table *data);
void		ph_init_philos(t_table *data);
void		ph_create_loop(t_table *data, t_philo *philo);
void		ph_create_philos(t_table *data, t_philo *philo);

// ph_time.c

uint64_t		ph_time(void);
void		ph_usleep(uint64_t time);

#endif
