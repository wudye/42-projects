#include "philo.h"



long long	get_current_time(void)
{
	struct timeval		current_time;
	long long			result;

	gettimeofday(&current_time, NULL);
	result = (current_time.tv_sec * 1000) + ((current_time.tv_usec) / 1000);
	return (result);
}

// long long   get_current_time(void)
// {
//     	struct timeval		current_time;
// 	long long			result;

// 	gettimeofday(&current_time, NULL);
// 	result = (current_time.tv_sec * 1000) + ((current_time.tv_usec) / 1000);
// 	return (result);
//     // struct timeval tv;

//     // if (gettimeofday(&tv, NULL))
//     //     return 0;
//     // return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
    
// }

long long get_time_diff(long long start)
{
    return (get_current_time() - start);
}

void print_status(t_philo *philo, char *str)
{
    pthread_mutex_lock(&philo->philo_mutex);
    get_time_diff(philo->table->start_time);
    printf("%lld  %d  %s\n",     get_time_diff(philo->table->start_time), philo->id, str);
    pthread_mutex_unlock(&philo->philo_mutex);

}

void    init(t_table *table)
{
    int i;

    i = 0;
    while (i < table->philo_numbers)
    {
        table->pholos[i].id = i + 1;
        table->pholos[i].left_fork_mutex = table->forks_mutex[i];
        table->pholos[i].right_fork_mutex = table->forks_mutex[(i + 1) % table->philo_numbers];
        table->pholos[i].eat_count = 0;
        table->pholos[i].eat_enough = FALSE;
        table->pholos[i].should_die = FALSE;
        table->pholos[i].table = table;
        table->pholos[i].time_since_last_meak = get_current_time();
        if (pthread_mutex_init(&(table->pholos[i].philo_mutex), NULL) != 0)
        {
            print_error(MUTEX_INIT);
            return ;
        }
        i++;
    }
    

}