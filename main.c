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

#include "inc/philosophers.h"

int ph_atoi(char *s)
{
  int res;

  res = 0;
  while (*s >= '0' && *s <= '9')
    res = (res * 10) + (*s++ - 48);
  return (res);
}

bool ph_args(char **argv)
{
  int ix;

  ix = 1;
  while (argv[ix])
    if (!ph_atoi(argv[ix++]))
      return (false);
  return (true);
}

int main(int argc, char **argv)
{
  if (argc < 5 || argc > 6)
    return (printf("Invalid number of arguments"), 2);
  if (!ph_args(argv))
    return (printf("Arguments where not optimal"), 3);

  return (42);
}

