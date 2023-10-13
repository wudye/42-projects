#include <stdlib.h>
int countnumbers(char **argv)
{
    int i;
    int count;

    i = 0;
    count = 0;
    while(argv[1][i] != '\0')
    {
        if (argv[1][i] >= '1' && argv[1][i] <= '4')
        {
            count++;
        }
        i++;
    }
    if (count != 16)
        return 0;
    return (count);
}
int     **setvalue(char **argv,  int n)
{
    int i;
    int j;
    int **tab;

    i = 0;
    j = 0;
    // allocate the memory for 2d Array tab;
    // the address memory for tab[i]
    tab = malloc(sizeof(int*) * (n / 4));
    while (argv[1][i])
    {
        // allowcate the memory for each column eg. tab[0][i]
        if (j % (n / 4) == 0)
            tab[j / (n / 4)] = malloc(sizeof(int) * (n / 4));
        //set value to the map array
        tab[j / (n / 4)][j % (n / 4)] = atoi(&argv[1][i]);
        i++;
        j++;
    }
    return (tab);
}
int **checkargv(int argc, char **argv, int *size)
{
    int argvnumbers = countnumbers(argv);
    int **inputarray;
    if (argvnumbers == 0)
        return 0;
    // arguments should be always 2
    if (argc == 2)
    {
        // set input values to  map
        inputarray = setvalue(argv, argvnumbers);
        // get the map row and colomn
        *size = argvnumbers / 4;
        return (inputarray);
    }
    return 0;
}