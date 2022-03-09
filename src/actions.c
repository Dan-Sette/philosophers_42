/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalves-s <dalves-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:02:16 by dalves-s          #+#    #+#             */
/*   Updated: 2022/03/09 18:51:15 by dalves-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	took_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->fork[philo->r_fork]);
	print_actions(M_TAKEN, philo);
	pthread_mutex_lock(&philo->table->fork[philo->l_fork]);
	print_actions(M_TAKEN, philo);
	
}



void	dropped_forks(t_philo *philo)
{
	pthread_mutex_unlock(&philo->table->fork[0]);
	pthread_mutex_unlock(&philo->table->fork[1]);
}