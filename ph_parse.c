/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifrost <bifrost@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 16:39:33 by bifrost           #+#    #+#             */
/*   Updated: 2023/08/31 16:39:34 by bifrost          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/philosophers.h"

uint64_t ph_atoi(char *s)
{
  uint64_t res;

  res = 0;
  while (*s >= '0' && *s <= '9')
    res = (res * 10) + (*s++ - 48);
  return (res);
}

bool ph_args(int argc, char **argv)
{
  int ix;

  if (argc < 5 || argc > 6)
  {
    printf("Error\n");
    return (false);
  }
  ix = 1;
  while (argv[ix])
    if (!ph_atoi(argv[ix++]))
      return (false);
  return (true);
}

