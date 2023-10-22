/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifrost <bifrost@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 13:28:33 by nkeyani-          #+#    #+#             */
/*   Updated: 2023/10/20 13:57:44 by bifrost          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/philosophers.h"

void    ph_print(char *color, t_philo *philo, char *s, bool dead)
{
    uint64_t    i;
    //bool        finish;
    
    dead = false;
    pthread_mutex_lock(&philo->table->print_mutex);
    pthread_mutex_lock(&philo->table->dead_mutex);
    dead = philo->table->is_dead;
    pthread_mutex_unlock(&philo->table->dead_mutex);
    i = ph_time() - philo->table->start;
    if (!philo->table->is_dead || dead == true)
        printf("%s%lu Philo[%d] %s\n%s", color, i, philo->id, s, E);
    pthread_mutex_unlock(&philo->table->print_mutex);
}
