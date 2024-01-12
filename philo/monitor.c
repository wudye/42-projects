#include "philo.h"


static  int eat_count_end(t_philo *philo)
{
    pthread_mutex_lock(&philo->philo_mutex);
    if (philo->eat_count == philo->table->eat_asked_times && philo->eat_enough == FALSE)
    {
        philo->eat_enough = TRUE;
        philo->table->philo_eat_numbers++;
        if (philo->table->philo_eat_numbers == philo->table->philo_numbers)
        {
            pthread_mutex_unlock(&philo->philo_mutex);
            return (1);
        }
    
    }
    pthread_mutex_unlock(&philo->philo_mutex);
        return (0);
}

static int  philo_die_check(t_philo *philo)
{
    pthread_mutex_lock(&philo->philo_mutex);
    if ((get_current_time() - philo->time_since_last_meak > philo->table->die_time))
    {
        pthread_mutex_unlock(&philo->philo_mutex);
        return (1);       
    }
    pthread_mutex_unlock(&philo->philo_mutex);
    return (0);
}

void    monitor(t_table *table)
{
    int i;

    i = 0;
   pthread_mutex_unlock(&table->table_mutex);
    while (1)
    {
        if (table->eat_asked_times && eat_count_end(&table->pholos[i]) != 0)
        {
            pthread_mutex_lock(&table->table_mutex);
            return ;
        }
        if (philo_die_check(&table->pholos[i]) != 0)
        {
            pthread_mutex_lock(&table->table_mutex);
            print_status(&table->pholos[i], "died");
            return ;

        }
        i++;
        i %= table->philo_numbers;           
    }
}

void exit_all_thread(t_table *table)
{
    int i;

    i = 0;
    while (i < table->philo_numbers)
    {
        pthread_mutex_lock(&(table->pholos[i].philo_mutex));
        table->pholos[i].should_die = TRUE;
        pthread_mutex_unlock(&(table->pholos[i].philo_mutex));
        i++;

    }
}

void free_all(t_table *table)
{
        int i;

    i = 0;
    pthread_mutex_destroy(&table->table_mutex);
    while (i < table->philo_numbers)
    {
        pthread_mutex_destroy(&(table->pholos[i].philo_mutex));
        pthread_mutex_destroy(&(table->forks_mutex[i]));
        i++;
    }
    free(table->forks_mutex);
    free(table->pholos);
    free(table);

}