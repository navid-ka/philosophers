/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifrost <nkeyani-@student.42barcelona.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 23:50:19 by bifrost           #+#    #+#             */
/*   Updated: 2023/08/18 21:26:55 by bifrost          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/time.h>
#include <time.h>

static int		g_count = 10;
pthread_mutex_t g_mutex = PTHREAD_MUTEX_INITIALIZER;

float time_diff(struct timeval *start, struct timeval *end)
{
    return (end->tv_sec - start->tv_sec) + 1e-6*(end->tv_usec - start->tv_usec);
}

int	loops(int NUM)
{
	struct timeval start;
    struct timeval end;
	for (int i = 0; i < NUM; i++){
		for (int j = 0; j < NUM; j++){
			pthread_mutex_lock(&g_mutex);
			gettimeofday(&start, NULL);
			g_count--;
			gettimeofday(&end, NULL);
			pthread_mutex_unlock(&g_mutex);
		}
		pthread_mutex_lock(&g_mutex);
		g_count++;
		pthread_mutex_unlock(&g_mutex);
	}
	return (g_count);
}

int	main(void)
{
	struct timeval start;
    struct timeval end;
	

    printf("loopFunc(%d) time spent: %0.8f sec\n", loops(200), time_diff(&start, &end));
	printf("Hello, Philosophers %d\n", g_count);
}
