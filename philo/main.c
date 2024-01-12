#include "philo.h"

void    print_error(t_error str)
{
    if (str == MALLOC)
        printf("ERROR\nfailed in malloc memory");
    if (str == MUTEX_INIT)
        printf("ERROR\nfailed in mutex init");
    if (str == PTHREAD_CREATE)
        printf("ERROR\nfailed in pthread create");
}

static void print_input_mesg(void)
{
    printf("ERROR\n");
    printf("the input arguments rules are all positive integer");
    printf("first number of philo o--200");
    printf("eat_time  > 60");
    printf("sleep_time  > 60");
    printf("eat times 1->INT_MAX");
}

static int  init_mutex(t_table *table)
{
    int i;

    i = 0;
    if (pthread_mutex_init(&(table->table_mutex), NULL) != 0)
        return (print_error(MUTEX_INIT), 1);
    while (i < table->philo_numbers)
    {
        if (pthread_mutex_init(&(table->forks_mutex[i]), NULL) != 0)
            return (print_error(MUTEX_INIT), 1);
        i++;
    }
    return (0);
}
static t_table  *init_table(char **argv)
{
    t_table *res;

    res = malloc(sizeof(t_table));
    if (!res)
        return(print_error(MALLOC), NULL);
    res->philo_numbers = atoi(argv[1]);
    res->die_time = atoi(argv[2]);
    res->eat_time = atoi(argv[3]);
    res->sleep_time = atoi(argv[4]);
    if (atoi(argv[5]) && atoi(argv[5]) != 0)
        res->eat_asked_times = atoi(argv[5]);
    res->forks_mutex = malloc(sizeof(pthread_mutex_t) * (atoi(argv[1]))); 
    if (!res->forks_mutex)
        return(print_error(MALLOC), NULL);
    res->philo_eat_numbers = 0;
    res->start_time = get_current_time();
    res->pholos = malloc(sizeof(t_philo) * (atoi(argv[1]))); 
    if (!res->pholos)
        return(print_error(MALLOC), NULL);
    if (init_mutex(res) != 0)
        return (NULL);
    return (res);
}

static void init_pthread(t_table *table)
{
    int i;
    i = 0;
   
    // table->start_time = get_current_time();

    while (i < table->philo_numbers)
    {

        pthread_create(&(table->pholos[i].philo_thread), NULL, *simulate, &(table->pholos[i]));

        i++;
    }
}
int main(int argc, char **argv)
{
    t_table *table;
    int i;
    i = 0;

    if(argc >6)
        return (print_input_mesg(), 1);
    // if (check_input(argc, argv) != 0)
    // {
    //     print_input_mesg();
    //     return (1);
    // }
    table = init_table(argv);

    init(table);
   
        pthread_mutex_lock(&(table->table_mutex));

    init_pthread(table);
  //  pthread_mutex_unlock(&table->table_mutex);

    monitor(table);
    exit_all_thread(table);
    pthread_mutex_unlock(&table->table_mutex);

    while (i < table->philo_numbers)
    {
        pthread_join(table->pholos[i].philo_thread, NULL);
        i++;
    }
    free_all(table);

    return (0);
}
