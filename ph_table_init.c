/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_table_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifrost <bifrost@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 20:51:28 by bifrost           #+#    #+#             */
/*   Updated: 2023/08/31 20:51:56 by bifrost          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/philosophers.h"

int ph_init_table(t_table *data, char **argv)
{
  data->ph_num = ph_atoi(argv[1]);
  data->time_to_die = ph_atoi(argv[2]);
  data->time_to_eat = ph_atoi(argv[3]);
  data->time_to_sleep = ph_atoi(argv[4]);
  return(0);
}
/*
void  ph_init_forks(t_table *data)
{
  // TODO: Init forks logic  
}

void  ph_init_philos(t_table *data)
{
  //TODO: Init philosophers logic
}
*/
