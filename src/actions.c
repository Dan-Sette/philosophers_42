/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalves-s <dalves-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:02:16 by dalves-s          #+#    #+#             */
/*   Updated: 2022/03/10 19:06:21 by dalves-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	took_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->fork[philo->r_fork]);
	print_actions(M_TAKEN, philo);
	if (philo->table->n_philo > 1)
	{
		pthread_mutex_lock(&philo->table->fork[philo->l_fork]);
		print_actions(M_TAKEN, philo);
	}
	else
	{
		usleep(philo->table->t_die * 1000);
		philo->table->dead_philo = true;
	}
}

void	eating(t_philo *philo)
{
	philo->last_meal = get_time();
	print_actions(M_EAT, philo);
	usleep(philo->table->t_eat * 1000);
	philo->meal_counter++;
}

void	*dropped_forks(t_philo *philo)
{
	pthread_mutex_unlock(&philo->table->fork[philo->r_fork]);
	pthread_mutex_unlock(&philo->table->fork[philo->l_fork]);
	return (NULL);
}

void	fall_asleep(t_philo *philo)
{
	print_actions(M_SLEEP, philo);
	dropped_forks(philo);
	usleep(philo->table->t_sleep * 1000);
}

void	thinking(t_philo *philo)
{
	print_actions(M_THINK, philo);
}