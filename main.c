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

int main(int argc, char **argv)
{
  if (argc < 5 || argc > 6)
    return (printf("Invalid number of arguments\n"));
  if (!ph_args(argv))
    return (printf("Arguments where not optimal\n"));

  return (42);
}

