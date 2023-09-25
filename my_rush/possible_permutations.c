// #include <stdio.h>
// #include <string.h>

// Function to swap two elements in an array
// void swap(char *x, char *y) {
//     char temp = *x;
//     *x = *y;
//     *y = temp;
// }

// // Function to generate all permutations of a sequence
// void generatePermutations(char *sequence, int start, int end) {
//     if (start == end) {
//         printf("%s\n", sequence); // Print the permutation
//     } else {
//         for (int i = start; i <= end; i++) {
//             swap(&sequence[start], &sequence[i]); // Swap characters
//             generatePermutations(sequence, start + 1, end); // Recursively generate permutations
//             swap(&sequence[start], &sequence[i]); // Backtrack (restore the original order)
//         }
//     }
// }

// int main() {
//     char sequence[] = "1234"; // Change this to your desired sequence
//     int length = strlen(sequence);

//     printf("All permutations of %s are:\n", sequence);
//     generatePermutations(sequence, 0, length - 1);

//     return 0;
// }


//consider numbers

// #include <stdio.h>
// #include <string.h>

// int countVisibleNumbers(const char *str) 
// {
//     int count;
//     int len;
//     int i;
//     int j;

//     i = 0;
//     j = 0;
//     count = 1;
//     len = strlen(str);
//     while (i < len) 
//     {
//         if (str[i] >= '0' && str[i] <= '9') 
//         {
//             if (str[j] < str[i + 1])
//             {
//                 count++;
//                 j++;
//                 if (j != i)
//                     j = i + 1;
//             }
//             i++;
//         }
//     }
//     return count;
// }

// int main() 
// {
//     const char *number = "154263798"; // Replace with your desired number

//     int result = countVisibleNumbers(number);

//     printf("The count of numbers seen before the largest is: %d\n", result);

//     return 0;
// }

#include <stdio.h>
#include <string.h>

int countVisibleNumbers(const char *str) {
    int count = 1; // Initialize count to 1, as the first digit is always visible
    int len = strlen(str);
    int i = 0;
    int j = 0;

    while (i < len - 1) { // Note: We only need to consider digits up to the second-to-last digit
        if (str[i] >= '0' && str[i] <= '9') {
            if (str[j] <= str[i + 1]) { // Compare the current digit with the next digit
                j = i + 1; // Reset j to the next digit
            } else {
                count++;
            }
        }
        i++;
    }

    return count;
}

int main() {
    const char *number = "154263798"; // Replace with your desired number

    int result = countVisibleNumbers(number);

    printf("The count of numbers seen before the largest is: %d\n", result);

    return 0;
}

