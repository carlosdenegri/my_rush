#include <stdio.h>

void print(char *str) {
    int array[4][4]; // Define a 4x4 array

    // Fill the array with digits (0-9)
    int digit = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            array[i][j] = digit;
            digit++;
        }
    }

    // Print the 4x4 array
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%2d ", array[i][j]); // Adjust the format to align the digits
        }
        printf("\n"); // Move to the next row
    }

    return 0;
}




// void print(char *str)
// {
//     int i;
//     int j;
//     int k;

//     i = 0;
//     while(i < 4)
//     {
//         j = 0;
//         while (j < 4)
//         {
//             while (str[k])
//             {
//                 k = 0;
//                 if (str[k] == 68)
//                 {
//                     k = k + 4;
//                     write (1, "|", 1);
//                     write (1, str[k], 1);
//                     write (1, "|", 1);
//                     write (1, str[k + 1], 1);
//                     write (1, "|", 1);
//                     write (1, str[k + 2], 1);
//                     write (1, "|", 1);
//                     write (1, str[k + 2], 1);
//                     write (1, "|", 1);                                                                                
 
//                 }
//             }
//             j++;
//         }
//         i++;
//     }
// }