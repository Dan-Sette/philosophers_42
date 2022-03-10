/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalves-s <dalves-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 11:54:17 by dalves-s          #+#    #+#             */
/*   Updated: 2022/03/10 18:53:47 by dalves-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_struct(int argc, char *argv[], t_table *table)
{
	table->n_philo = ft_atoi(argv[1]);
	table->t_die = ft_atoi(argv[2]);
	table->t_eat = ft_atoi(argv[3]);
	table->t_sleep = ft_atoi(argv[4]);
	table->fork = malloc(sizeof(pthread_mutex_t) * table->n_philo);
	table->philo = malloc(sizeof(t_philo) * table->n_philo);
	table->start = get_time();
	memset(table->fork, 0, sizeof(pthread_mutex_t));
	pthread_mutex_init(&table->print, NULL);
	table->dead_philo = false;
	if (argc == 6)
		table->meals = ft_atoi(argv[5]);
	else
		table->meals = -1;
}

void	init_philo(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->n_philo)
	{
		table->philo[i].meal_counter = 0;
		table->philo[i].table = table;
		table->philo[i].id = i + 1;
		table->philo[i].last_meal = get_time();
		pthread_mutex_init(&table->fork[i], NULL);
		pthread_mutex_init(&table->philo[i].mutex, NULL);
		table->philo[i].r_fork = i;
		table->philo[i].l_fork = i + 1;
		i++;
	}
	table->philo[i - 1].l_fork = 0;
}
