
#include "philo.h"

void    action_time_extend(long long tm)
{
    long  long current_time;
    long  long start;

    start = get_current_time();
    while (1)
    {
        current_time = get_current_time();
        if (current_time - start > tm)
            return ;
        usleep(100);
    }
    
}
static void philo_think(t_philo *philo)
{
    pthread_mutex_lock(&(philo->table->table_mutex));
    print_status(philo, "is thinking");
    pthread_mutex_unlock(&(philo->table->table_mutex));

}

static void handle_one_simulate(t_philo *philo)
{
    philo_think(philo);

    pthread_mutex_lock(&philo->left_fork_mutex);
    pthread_mutex_lock(&(philo->table->table_mutex));

    print_status(philo, "taken a fork");
    //print_status(philo, "died");

        pthread_mutex_unlock(&(philo->table->table_mutex));
       // philo->table->start_time = get_current_time();
        action_time_extend(philo->table->die_time + 2);

    pthread_mutex_unlock(&philo->left_fork_mutex);
    // exit(1);

}

static void handel_normal(t_philo *philo)
{
    philo_think(philo);
    // if (philo->id == 3)
    //     action_time_extend(1);
    if (philo->id % 2 == 1)
    {
        philo_eat(philo);
        philo_sleep(philo);
        philo_think(philo);
    }
    else
    {
        philo_sleep(philo);
        philo_think(philo);
    }
    while (1)
    {
        if (check_philo_finished(philo) == TRUE)
            return ;
        philo_eat(philo);
        philo_sleep(philo);
        philo_think(philo);
    }
    
}
void    *simulate(void *args)
{
    t_philo *philo;
    philo = (t_philo *) args;

    pthread_mutex_lock(&philo->philo_mutex);
    philo->time_since_last_meak = get_current_time();
    pthread_mutex_unlock(&philo->philo_mutex);

    if (philo->table->philo_numbers == 1)
        handle_one_simulate(philo);
    else
    {
        handel_normal(philo);
    }
    return(NULL);

}

