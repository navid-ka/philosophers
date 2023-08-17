/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifrost <nkeyani-@student.42barcelona.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 23:50:19 by bifrost           #+#    #+#             */
/*   Updated: 2023/08/18 00:26:38 by bifrost          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

static int		g_count = 10;
pthread_mutex_t g_mutex = PTHREAD_MUTEX_INITIALIZER;

int	main(void)
{
	for (int i = 0; i < 1000; i++){
		for (int j = 0; j < 1000; j++){
			pthread_mutex_lock(&g_mutex);
			g_count--;
			pthread_mutex_unlock(&g_mutex);
		}
		pthread_mutex_lock(&g_mutex);
		g_count++;
		pthread_mutex_unlock(&g_mutex);
	}
	printf("Hello, Philosophers %d\n", g_count);
}
