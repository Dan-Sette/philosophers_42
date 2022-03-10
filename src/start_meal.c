/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_meal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalves-s <dalves-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 16:00:03 by dalves-s          #+#    #+#             */
/*   Updated: 2022/03/10 18:15:00 by dalves-s         ###   ########.fr       */
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
		if (philo->table->dead_philo || !philo->alive)
			return (NULL);
		eating(philo);
		dropped_forks(philo);
		if (philo->table->dead_philo || !philo->alive)
			return (NULL);
		fall_asleep(philo);
		if (philo->table->dead_philo || !philo->alive)
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
	while (i < table->n_philo)
	{
		pthread_create(&table->philo[i].persona, NULL, &routine, &table->philo[i]);
		i++;
	}
	pthread_create(&checker, NULL, &check_pulse, table);
	pthread_detach(checker);
	i = 0;
	while (i < table->n_philo)
	{
		pthread_join(table->philo[i].persona, NULL);
		i++;
	}
}
