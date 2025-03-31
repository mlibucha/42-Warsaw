/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: e <e@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 11:29:06 by e                 #+#    #+#             */
/*   Updated: 2025/03/31 21:04:46 by e                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <pthread.h>
#include <stdbool.h>
#include <string.h>
#include <sys/time.h>


typedef struct s_fork {
    pthread_mutex_t mutex;
    int             id;
} t_fork;

typedef struct s_philo {
    int             id;
    pthread_t       thread;
    t_fork          *left_fork;
    t_fork          *right_fork;
    long long       time_to_die;
    long long       time_to_eat;
    long long       time_to_sleep;
    int             num_meals;
    int             meals_eaten;
    long long       last_meal_time;
    bool            full;
    pthread_mutex_t meal_mutex;
    struct s_data   *data;
} t_philo;

typedef struct s_data {
    int             num_philosophers;
    t_philo         *philos;
    t_fork          *forks;
    long long       start_time;
    bool            someone_died;
    pthread_mutex_t print_mutex;
    pthread_mutex_t death_mutex;
} t_data;

#define RED   "\033[31m"
#define GREEN "\033[32m"
#define BLUE  "\033[34m"
#define RESET "\033[0m"

//create
int init_data(t_data *data, int argc, char **argv);
int create_threads(t_data *data);
//runtime

void        *philosopher_routine(void *arg);
void        *monitor_routine(void *arg);
long long   get_timestamp_ms(void);
void        print_status(t_philo *philo, char *message, char *color);
void        cleanup(t_data *data);
int         error_msg(char *msg);
int	ft_atoi(const char *c);
int check_input(int argc, char **argv);
void print_death(t_philo *philo);
void print_all_full(t_data *data);
bool check_death(t_philo *philo);
void init_timer(void);
#endif
