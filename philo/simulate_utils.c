#include "philo.h"

void philo_eat(t_philo *philo)
{
    pthread_mutex_lock(&philo->left_fork_mutex);
    pthread_mutex_lock(&philo->right_fork_mutex);
    pthread_mutex_lock(&(philo->table->table_mutex));
    print_status(philo, "has taken a fork");
    print_status(philo, "has taken a fork");
        print_status(philo, "is eating");

    pthread_mutex_lock(&philo->philo_mutex);
    philo->eat_count++;
    philo->time_since_last_meak = get_current_time();
    pthread_mutex_unlock(&philo->philo_mutex);
    pthread_mutex_unlock(&(philo->table->table_mutex));
    action_time_extend(philo->table->eat_time);
    pthread_mutex_unlock(&philo->left_fork_mutex);
    pthread_mutex_unlock(&philo->right_fork_mutex);

}

void philo_sleep(t_philo *philo)
{
        pthread_mutex_lock(&(philo->table->table_mutex));
    print_status(philo, "is sleeping");
    pthread_mutex_unlock(&(philo->table->table_mutex));
    action_time_extend(philo->table->sleep_time);

}

t_bool check_philo_finished(t_philo *philo)
{
    t_bool  res;
    pthread_mutex_lock(&philo->philo_mutex);
    res = philo->should_die;
    pthread_mutex_unlock(&philo->philo_mutex);
    return (res);

}