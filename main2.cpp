#include <stdio.h>

int main() {
    int n;
    printf("Matris boyutunu girin: ");
    scanf("%d", &n);
    
    int matrix[n][n];
    printf("Matrisi girin:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            int num = matrix[i][j];
            if (num <= 1) continue;
            int is_prime = 1;
            for (int k = 2; k * k <= num; k++) {
                if (num % k == 0) {
                    is_prime = 0;
                    break;
                }
            }
            if (is_prime) count++;
        }
    }
    
    printf("Alt üçgende %d asal sayı var.\n", count);
    return 0;
}