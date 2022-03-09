/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_meal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalves-s <dalves-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 16:00:03 by dalves-s          #+#    #+#             */
/*   Updated: 2022/03/09 18:43:01 by dalves-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *philo)
{
	t_philo *p;

	p = philo;
	if (p->id % 2 == 0)
		usleep(2000);
	took_forks(p);
	//comer t_eat de tempo (printar)
	dropped_forks(p);
	//dormir t_sleep de tempo (printar)
	//pensar t_die enquanto espera pra comer(printar)
	return (NULL);
}

void	start_meal(t_table *table)
{
	int	i;

	i = 0;
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
}