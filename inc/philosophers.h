/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkeyani- <nkeyani-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 23:50:26 by bifrost           #+#    #+#             */
/*   Updated: 2023/10/24 16:31:56 by nkeyani-         ###   ########.fr       */
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
// ================================= COLORS ================================= /

# define E "\033[m"        //end
# define R "\033[1;31m"    //red
# define G "\033[1;32m"    //green
# define Y "\033[1;33m"    //yellow
# define B "\033[1;34m"    //blue
# define T "\033[1;35m"	   //Turquesa
# define C "\033[1;36m"    //Cyan
# define O "\033[38;5;208m" //orange
# define F "\033[38;5;128m"  //purple

// ================================= MESSAGES =============================== //

# define FORK "has taken a fork"
# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define DEAD "died"

typedef struct s_philo
{
	struct s_table	*table;
	int				id;
	int				time_die;
	uint64_t		times_eaten;
	uint64_t		last_meal;
	pthread_t		t;
	pthread_mutex_t	time_die_mutex;
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
	uint64_t		meals;
	uint64_t		meals_finished;
	uint64_t		start;
	bool			is_dead;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	dead_mutex;
	pthread_mutex_t	start_mutex;
}	t_table;

// ph_parse.c

uint64_t	ph_atoi(char *s);
bool		ph_args(int argc, char **argv);

// ph_table_init.c

int			ph_init_table(t_table *data, char **argv);
void		ph_init_philos(t_table *data);
void		ph_create_philos(t_table *data);

// ph_trheads.c

void		routine(t_philo *philo);
void		control(t_table *data);

// ph_time.c

uint64_t	ph_time(void);
void		ph_usleep(uint64_t time);

// ph_print.c
void		ph_print(char *color, t_philo *philo, char *s, bool dead);

#endif
