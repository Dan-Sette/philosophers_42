/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalves-s <dalves-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:02:16 by dalves-s          #+#    #+#             */
/*   Updated: 2022/03/10 18:09:48 by dalves-s         ###   ########.fr       */
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
		philo->alive = false;
	}
	
}

void	eating(t_philo *philo)
{
	philo->last_meal = get_time();
	print_actions(M_EAT, philo);
	usleep(philo->table->t_eat * 1000);
	philo->meal_counter++;
}

void	dropped_forks(t_philo *philo)
{
	pthread_mutex_unlock(&philo->table->fork[philo->r_fork]);
	pthread_mutex_unlock(&philo->table->fork[philo->l_fork]);
}

void	fall_asleep(t_philo *philo)
{
	usleep(philo->table->t_sleep * 1000);
	print_actions(M_SLEEP, philo);
}

void	thinking(t_philo *philo)
{
	print_actions(M_THINK, philo);
}