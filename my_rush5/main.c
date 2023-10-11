#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main()
{
    int i = 0;
    int j = 0;
    int k = 0;
    int length;
    char my_str;
    char return_str[5];
    char argument[] = "1221233214224122";
    char arg[3];
    char sequence[] = "1234"; 

    length = strlen(sequence);
    my_str = calloc (999, 1);

    while (argument[i])
    {
        if (j < 2)
        {
            arg[j] = argument[i];
            j++;
            i++;
        }
        if (j == 2)
        {
            arg[j] = 0;
            j = 0;
            my_str = generatePermutations(sequence, 0, length - 1, arg);
        }
    }
    return 0;
}