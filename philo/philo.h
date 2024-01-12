#ifndef PHILO_H
# define PHILO_H

// # include <stdio.h> // test
// # include <pthread.h>
// # include <unistd.h>
// # include <string.h>
// # include <stdlib.h>
// # include <sys/time.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <limits.h>
# include <sys/time.h>
typedef struct s_table  t_table;

typedef enum s_error
{
    MALLOC,
    MUTEX_INIT,
    PTHREAD_CREATE
}   t_error;

typedef enum s_bool
{
    FALSE = 0,
    TRUE = 1
} t_bool;

typedef struct  s_philo
{
    int     id;
    int     eat_count;
    t_bool  should_die;
    t_bool  eat_enough;
    t_table *table;
    long long   time_since_last_meak;
    pthread_mutex_t left_fork_mutex;
    pthread_mutex_t right_fork_mutex;
    pthread_t       philo_thread;
    pthread_mutex_t philo_mutex;

    
} t_philo;

typedef struct s_table
{
    int philo_numbers;
    int die_time;
    int eat_time;
    int sleep_time;
    int eat_asked_times;
    pthread_mutex_t *forks_mutex;
    pthread_mutex_t table_mutex;
    t_philo *pholos;
    int philo_eat_numbers;
    long long   start_time;
} t_table;

int main(int argc, char **argv);
void    print_error(t_error str);
long long    get_current_time(void);
void print_status(t_philo *philo, char *str);
void    init(t_table *table);
void    monitor(t_table *table);
void    *simulate(void *args);
void exit_all_thread(t_table *table);
void free_all(t_table *table);
void philo_eat(t_philo *philo);
void    action_time_extend(long long tm);
t_bool check_philo_finished(t_philo *philo);
void philo_sleep(t_philo *philo);
void philo_eat(t_philo *philo);

#endif