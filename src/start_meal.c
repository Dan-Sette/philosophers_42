/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_meal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalves-s <dalves-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 16:00:03 by dalves-s          #+#    #+#             */
/*   Updated: 2022/03/10 22:05:20 by dalves-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *ph)
{
	t_philo *philo;

	philo = ph;
	if (philo->id % 2 == 0)
		usleep(1600);
	while (!philo->table->dead_philo)
	{
		took_forks(philo);
		if (philo->table->dead_philo)
			return (dropped_forks(philo));
		eating(philo);
		if (philo->table->dead_philo)
			return (dropped_forks(philo));
		fall_asleep(philo);
		if (philo->table->dead_philo)
			return (NULL);
		thinking(philo);
	}
	return (NULL);
}

void	start_meal(t_table *table)
{
	int	i;
	pthread_t checker;

	i = 0;
	pthread_create(&checker, NULL, &check_pulse, table);
	while (i < table->n_philo)
	{
		pthread_create(&table->philo[i].persona, NULL, &routine, &table->philo[i]);
		i++;
	}
	i = 0;
	while (i < table->n_philo)
	{
		pthread_join(table->philo[i].persona, NULL);
		i++;
	}
	pthread_join(checker, NULL);
}
