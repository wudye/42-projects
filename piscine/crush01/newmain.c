#include <unistd.h>
#include <stdio.h>
int main(int argv1, char **argc1)
{
    int i;
    int j;
    i = 0;
    j = 0;
    int k = 0;
    int size = 4;
    int temparray[16];
    int gambeboard[4][4];
    int table[4][4];
    char argc[132] = "1 3 2 1 1 2 2 2 1 3 2 1 1 2 2 2";
    int argv = 2;
    if (argv == 2)
    {
        printf("1\n");
        while (argc[i] != '\0')
        {   if (argc[i] >= '1' && argc[i] <= '4')
                {
                    temparray[j] = argc[i] - 48;
                    j++;
                }
            i++;
        }
        printf("j = %d\n", j);
        i = 0;
        while (i < 4)
        {
            j = 0;
            while(j < 4)
            {
                gambeboard[i][j] = temparray[k];
                j++;
                k++;
            }
            i++;
        }
        //gameboard[0] ==== colup
        //gameboard[1] ==== coldown
        //gameboard[2] ==== rowleft
        //gameboard[3] ==== rowright
        // use colup give table[0][j]
        i = 0;

            j = 0;
            while (j < size)    
            {
                if (gambeboard[i][j] == 4)
                    table[i][j] = 1;
                if (gambeboard[i][j] == 1)
                    table[i][j] = 4;
                if (gambeboard[i][j] == 3)
                    table[i][j] = 2;
                if (gambeboard[i][j] == 2)
                    table[i][j] = 3;
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
        i = 0;
        while (i < 4)
        {
            j = 0;
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

        i  = 0;
        while (i < size)
        {
            j = 0;
            while (j < size)
            {
                printf("%d\t",  table[i][j]);
                j++;
            }   
            printf("\n");
            i++;
        }
    }
}