#include <iostream>
using namespace std;

// Dizi içinde iki elemanı yer değiştirmek için swap fonksiyonu
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Dizinin bir parçasını pivot etrafında bölen partition fonksiyonu
int partition(int A[], int low, int high) {
    int pivot = A[high];  // Pivot olarak son eleman seçiliyor
    int i = low - 1;  // i, pivot'un doğru yerine yerleştirileceği indeksi takip eder

    for (int j = low; j < high; j++) {
        if (A[j] < pivot) {
            i++;  // i'yi arttır ve küçük elemanları sol tarafa taşı
            swap(A[i], A[j]);
        }
    }
    swap(A[i + 1], A[high]);  // Pivot'u doğru yerine yerleştir
    return i + 1;  // Pivot'un yerini döndür
}

// Rekürsif quick sort fonksiyonu
void quickSort(int A[], int low, int high) {
    if (low < high) {
        int pi = partition(A, low, high);  // Pivot'u partition et

        // Sol tarafı sırala
        quickSort(A, low, pi - 1);

        // Sağ tarafı sırala
        quickSort(A, pi + 1, high);
    }
}

int main() {
    int A[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(A) / sizeof(A[0]);

    quickSort(A, 0, n - 1);  // Quick sort'u çağır

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;

    return 0;
}
