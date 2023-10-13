#include <unistd.h>
void outputtable(int **table, int size)
{
    int i;
    int j;
    i  = 0;
    
    while (i < size)
    {
        j = 0;
        while (j < size)
        {
            write(1, &table[i][j], 1);
            j++;
        }   
        write(1, "\n", 1); 
        i++;
    }
}
void drawboard(int **gambeboard, int size)
{
    int i, j;
    int **table;
    table = malloc(sizeof(int *) * size);

    //gameboard[0] ==== colup
    //gameboard[1] ==== coldown
    //gameboard[2] ==== rowleft
    //gameboard[3] ==== rowright
    i = 0;
    // use colup give table[0][j]
    i = 0;
    
        j = 0;
        while (j < size)    
        {
            if (gambeboard[i][j] == 4)
                table[i+1][j] = 1;
            if (gambeboard[i][j] == 1)
                table[i+1][j] = 4;
            if (gambeboard[i][j] == 3)
                table[i+1][j] = 2;
            if (gambeboard[i][j] == 2)
                table[i+1][j] = 3;
            j++;
        }
     
    //coldown
    i = 1;
   
        j = 0;
        while (j < size)    
        {
            if (gambeboard[i][j] == 4)
                table[3][j] = 1;
            if (gambeboard[i][j] == 1)
                table[3][j] = 4;
            j++;
        }
    
    // use rowleft give vale table[j][0]
    i = 2;
        j = 0;
        while (j < size)    
        {
            if (gambeboard[i][j] == 4)
                table[j][0] = 1;
            if (gambeboard[i][j] == 1)
                table[j][0] = 4;
            if (gambeboard[i][j] == 3)
                table[j][0] = 2;
            if (gambeboard[i][j] == 2)
                table[j][0] = 3;
            j++;
        }
    // give table rest value
    i = 1;
    while (i < 4)
    {
        j = 1;
        while(j+1 < 4)
        {
            if (table[i][j] == 4)
                table[i][j+1] = 1;
            else
                table[i][j+1] = table[i][j] + 1;
                j++;
        }
        i++;
    }
    outputtable(table, size);

}