#include <stdio.h>
#include <string.h>

// int countVisibleNumbers(const char *str) {
//     int count = 1; // Initialize count to 1, as the first digit is always visible
//     int len = strlen(str);
//     int i = 0;
//     int j = 0;

//     while (i < len - 1) { // Note: We only need to consider digits up to the second-to-last digit
//         if (str[i] >= '0' && str[i] <= '9') {
//             if (str[j] > str[i + 1]) { // Compare the current digit with the next digit
//                 j = j + 0; // Reset j to the next digit
//             } else {
//                 count++;
// 				j = i + 1;
//             }
//         }
//         i++;
//     }

//     return count;
// }

int reversedcountVisibleNumbers(const char *str) {
    int count = 1; // Initialize count to 1, as the first digit is always visible
    int len = strlen(str);
    int i = len;
    int j = len;

    while (i > 0 + 1) { // Note: We only need to consider digits up to the second-to-last digit
        if (str[i] >= '0' && str[i] <= '9') {
            if (str[j] > str[i - 1]) { // Compare the current digit with the next digit
                j = j + 0; // Reset j to the next digit
            } else {
                count++;
				j = i - 1;
            }
        }
        i--;
    }

    return count;
}

int main() {
    const char *number = "954863712"; // Replace with your desired number

    int result = reversedcountVisibleNumbers(number);

    printf("The count of numbers seen before the largest is: %d\n", result);

    return 0;
}
