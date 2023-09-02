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
# include <string.h>
# include <stdint.h>

typedef struct s_philo
{
  struct s_table  *table;
  int             id;
  pthread_mutex_t l_fork;
  pthread_mutex_t *r_fork;
} t_philo;

typedef struct s_table
{
  t_philo   *philo;
  uint64_t  ph_num;
  uint64_t  time_to_die;
  uint64_t  time_to_eat;
  uint64_t  time_to_sleep;
} t_table;

// ph_parse.c

uint64_t  ph_atoi(char *s);
bool      ph_args(int argc, char **argv);

// ph_table_init.c

void  ph_init_table(t_table *data, char **argv);
void  ph_init_forks(t_table *data);
void  ph_init_philos(t_table *data);

#endif
