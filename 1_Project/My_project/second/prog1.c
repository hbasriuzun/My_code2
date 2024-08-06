#include <stdio.h>

void Numeric2Char(char A[], int numeric) {
    int i;
    for (i = 7; i >= 0; i--) {
        A[i] = (numeric % 10) + '0'; 
        numeric /= 10; 
    }
    A[8] = '\0'; 
}

int Char2Numeric(char A[]) {
    int numeric = 0,i;
    for (i = 0; i < 8; i++) {
        numeric = numeric * 10 + (A[i] - '0'); 
    }
    return numeric;
}

int main() {
    int choice;
    char A[9];
    int numeric;
    int result;

    printf("Choose an option:\n");
    printf("To convert integer to char, press 1.\n");
    printf("To convert char to integer, press 2.\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter the numerical value with 8 digits: ");
            scanf("%d", &numeric);

            Numeric2Char(A, numeric);
            printf("The character representation: %s\n", A);
            break;
        case 2:
            printf("Enter the string representation with 8 characters: ");
            scanf("%s", A);

            result = Char2Numeric(A);
            printf("The integer representation: %d\n", result);
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }

    return 0;
}
