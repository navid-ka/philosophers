/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifrost <bifrost@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 23:50:26 by bifrost           #+#    #+#             */
/*   Updated: 2023/08/31 20:52:46 by bifrost          ###   ########.fr       */
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

typedef struct s_philo
{
  struct          s_table *table;
  int             ph_id;
  pthread_mutex_t *left_fork;
  pthread_mutex_t *rightfork;
} t_philo;

typedef struct s_table
{
  t_philo *philos;
  int     ph_num;
  int     time_to_die;
  int     time_to_eat;
  int     time_to_sleep;
} t_table;

// ph_parse.c

int   ph_atoi(char *s);
bool  ph_args(char **argv);

// ph_table_init.c

int   ph_init_table(t_table *data, char **argv);
void  ph_init_forks(t_table *data);
void  ph_init_philos(t_table *data);

#endif
