/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   watching.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalves-s <dalves-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 11:52:00 by dalves-s          #+#    #+#             */
/*   Updated: 2022/03/11 09:42:53 by dalves-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	check_aux(t_table *table)
{
	int	counter;
	int	enough;

	counter = 0;
	enough = 0;
	while (counter < table->n_philo)
	{
		if (get_time() - table->philo[counter].last_meal > table->t_die)
		{
			print_actions(M_DIED, &table->philo[counter]);
			return (true);
		}
		if (table->philo[counter].meal_counter >= table->meals)
			enough++;
		if (enough == table->n_philo)
			return (true);
		counter++;
	}
	return (false);
}

void	*check_pulse(void *tb)
{
	t_table	*table;

	table = tb;
	while (!table->dead_philo)
	{
		table->dead_philo = check_aux(table);
		usleep(500);
	}
	return (NULL);
}
