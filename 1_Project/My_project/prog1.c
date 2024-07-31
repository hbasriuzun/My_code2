#include <stdio.h>

// 8 basamaklı bir tam sayıyı karakter dizisine dönüştürme fonksiyonu
void Numeric2Char(char A[], int numeric) {
    // Her basamağı karakter dizisine yerleştir
    for (int i = 7; i >= 0; i--) {
        A[i] = (numeric % 10) + '0'; 
        numeric /= 10; 
    }
    A[8] = '\0'; 
}

// Karakter dizisini 8 basamaklı bir tam sayıya dönüştürme fonksiyonu
int Char2Numeric(char A[]) {
    int numeric = 0;
    for (int i = 0; i < 8; i++) {
        numeric = numeric * 10 + (A[i] - '0'); // Her karakteri sayıya dönüştür ve toplama ekle
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

    if (choice == 1) {
        printf("Enter the numerical value with 8 digits: ");
        scanf("%d", &numeric);

        Numeric2Char(A, numeric);
        printf("The character representation: %s\n", A);
    } else if (choice == 2) {
        printf("Enter the string representation with 8 characters: ");
        scanf("%s", A);

        result = Char2Numeric(A);
        printf("The integer representation: %d\n", result);
    } else {
        printf("Invalid choice.\n");
    }

    return 0;
}
