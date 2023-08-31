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
  t_table *data;

  data = malloc(sizeof(data));
  if (argc < 5 || argc > 6)
    return (printf("Invalid number of arguments\n"));
  if (!ph_args(argv))
    return (printf("Arguments where not optimal\n"));
  ph_init_table(data, argv);
  printf("ph_num : %d\ntime_to_die : %d\ntime_to_eat : %d\ntime_to_sleep : %d\n", \
         data->ph_num, data->time_to_die, data->time_to_eat, data->time_to_sleep);

  return (42);
}

