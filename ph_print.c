/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkeyani- <nkeyani-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 13:28:33 by nkeyani-          #+#    #+#             */
/*   Updated: 2023/10/24 16:33:01 by nkeyani-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/philosophers.h"

void	ph_print(char *color, t_philo *philo, char *s, bool dead)
{
	uint64_t	i;
	bool		finish;

	pthread_mutex_lock(&philo->table->print_mutex);
	pthread_mutex_lock(&philo->table->dead_mutex);
	finish = philo->table->is_dead;
	pthread_mutex_unlock(&philo->table->dead_mutex);
	i = ph_time() - philo->table->start;
	if (!finish || dead == true)
		printf("%s%llu Philo[%d] %s\n%s", color, i, philo->id, s, E);
	pthread_mutex_unlock(&philo->table->print_mutex);
}
