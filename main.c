/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifrost <bifrost@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 23:50:19 by bifrost           #+#    #+#             */
/*   Updated: 2023/08/31 20:51:43 by bifrost          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/philosophers.h"

int main(int argc, char **argv)
{
  t_table data;
  
  memset(&data, 0, sizeof(data));
  if (!ph_args(argc, argv))
    return (printf("Arguments where not optimal\n"));
  ph_init_table(&data, argv);
  ph_init_philos(&data);
  printf("ph_num : %ld\ntime_to_die : %ld\ntime_to_eat : %ld\ntime_to_sleep : %ld\n", \
         data.ph_num, data.time_to_die, data.time_to_eat, data.time_to_sleep);
  free(data.philo);
  exit(EXIT_SUCCESS);
}

