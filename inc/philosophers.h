/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifrost <nkeyani-@student.42barcelona.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 23:50:26 by bifrost           #+#    #+#             */
/*   Updated: 2023/08/20 15:07:59 by bifrost          ###   ########.fr       */
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
} t_table;

// ph_parse.c

int   ph_atoi(char *s);
bool  ph_args(char **argv);

#endif
