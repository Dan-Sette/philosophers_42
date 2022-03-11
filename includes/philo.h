/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalves-s <dalves-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 16:20:38 by dalves-s          #+#    #+#             */
/*   Updated: 2022/03/11 09:46:13 by dalves-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <stdbool.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

# define M_TAKEN    "has taken a fork"
# define M_EAT      "is eating"
# define M_SLEEP    "is sleeping"
# define M_THINK    "is thinking"
# define M_DIED     "died"

typedef struct s_table	t_table;
typedef struct s_philo	t_philo;

struct s_philo
{
	int				id;
	long int		last_meal;
	int				r_fork;
	int				l_fork;
	int				meal_counter;
	pthread_t		persona;
	pthread_mutex_t	mutex;
	t_table			*table;
};

struct s_table
{
	int				n_philo;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				meals;
	long int		start;
	bool			dead_philo;
	pthread_mutex_t	*fork;
	pthread_mutex_t	print;
	t_philo			*philo;
};

int			main(int argc, char *argv[]);
int			handle_args(char *argv[]);
void		init_struct(int argc, char *argv[], t_table *table);
int			ft_atoi(const char *str);
int			check_is_int(char *str);
void		init_philo(t_table *table);
long int	get_time(void);
void		start_meal(t_table *table);
void		*routine(void *ph);
void		print_actions(const char *str, t_philo *philo);
void		do_free(t_table *table);
void		took_forks(t_philo *philo);
void		eating(t_philo *philo);
void		*dropped_forks(t_philo *philo);
void		fall_asleep(t_philo *philo);
void		thinking(t_philo *philo);
void		*check_pulse(void *tb);

#endif