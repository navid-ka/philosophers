/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifrost <bifrost@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 23:50:19 by bifrost           #+#    #+#             */
/*   Updated: 2023/08/23 22:32:24 by bifrost          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/time.h>
#include <time.h>
#include "inc/philosophers.h"

static int NUM  = 2000;

static int      g_count = 10;
pthread_mutex_t g_mutex = PTHREAD_MUTEX_INITIALIZER;


float	time_diff(struct timeval *start, struct timeval *end)
{
	return (end->tv_sec - start->tv_sec) + 1e-6*(end->tv_usec - start->tv_usec);
}

int philo_eat(t_philo *philo, int NUM)
{
	return (philo->eat = NUM);
}

int	loops_a(int NUM)
{
  struct timeval start;
  struct timeval end;
	gettimeofday(&start, NULL);
	for (int i = 0; i < NUM; i++){
		pthread_mutex_lock(&g_mutex);
		g_count++;
		pthread_mutex_unlock(&g_mutex);
	}
	gettimeofday(&end, NULL);
	return (g_count);
}

int loops_b(int NUM)
{
	struct timeval start;
    struct timeval end;
	gettimeofday(&start, NULL);
	for (int i = 0; i < NUM; i++){
		pthread_mutex_lock(&g_mutex);
		g_count--;
		pthread_mutex_unlock(&g_mutex);
	}
	gettimeofday(&end, NULL);
	return (g_count);
}

int main(void)
{
	struct timeval start;
    struct timeval end;
	
	t_philo *philo = malloc(sizeof ((*philo)) + 1);
	gettimeofday(&start, NULL);
	philo->eat = 0;
	printf("%d\n", philo->eat);
	philo_eat(philo, NUM);
	printf("%d\n", philo->eat);
	gettimeofday(&end, NULL);
	printf("loopFunc(%d) time spent: %0.8f sec\n", philo_eat(philo, NUM), time_diff(&start, &end));
	printf("loop_a(%d) loop_a(%d) time spent: %0.8f sec\n", loops_a(NUM), loops_b(NUM), time_diff(&start, &end));
}
