/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalves-s <dalves-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 15:33:53 by dalves-s          #+#    #+#             */
/*   Updated: 2022/03/09 18:50:08 by dalves-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long int	get_time(void)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return (now.tv_sec * 1000 + now.tv_usec / 1000);
}

void	print_actions(const char *str, t_philo *philo)
{
	pthread_mutex_lock(&philo->table->print);
	printf("%ld     %d %s\n", get_time() - philo->last_meal, philo->id, str);
	pthread_mutex_unlock(&philo->table->print);
}

void	do_free(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->n_philo)
	{
		pthread_mutex_destroy(&table->fork[i]);
		i++;
	}
	pthread_mutex_destroy(&table->print);
}
