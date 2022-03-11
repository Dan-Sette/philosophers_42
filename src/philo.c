/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalves-s <dalves-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 16:20:08 by dalves-s          #+#    #+#             */
/*   Updated: 2022/03/11 09:44:55 by dalves-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	handle_args(char *argv[])
{
	int		i;

	i = 1;
	while ((void *)argv[i] != NULL)
	{
		if (check_is_int(argv[i]))
		{
			printf("Error\n");
			return (1);
		}
		i++;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_table	table;

	if (argc < 5 || argc > 6 || *argv[1] == '0')
	{
		printf("Error\n");
		return (1);
	}
	if (handle_args(argv))
		return (1);
	init_struct(argc, argv, &table);
	init_philo(&table);
	start_meal(&table);
	do_free(&table);
	return (0);
}
