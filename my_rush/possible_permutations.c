#include <stdio.h>
#include <string.h>

// Function to swap two elements in an array
void swap(char *x, char *y) {
    char temp = *x;
    *x = *y;
    *y = temp;
}

// Function to generate all permutations of a sequence
void generatePermutations(char *sequence, int start, int end) {
    if (start == end) {
        printf("%s\n", sequence); // Print the permutation
    } else {
        for (int i = start; i <= end; i++) {
            swap(&sequence[start], &sequence[i]); // Swap characters
            generatePermutations(sequence, start + 1, end); // Recursively generate permutations
            swap(&sequence[start], &sequence[i]); // Backtrack (restore the original order)
        }
    }
}

int main() {
    char sequence[] = "1234"; // Change this to your desired sequence
    int length = strlen(sequence);

    printf("All permutations of %s are:\n", sequence);
    generatePermutations(sequence, 0, length - 1);

    return 0;
}
