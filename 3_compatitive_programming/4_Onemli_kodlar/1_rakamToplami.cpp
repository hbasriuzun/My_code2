#include <iostream>
#include <cstdlib> // abs() fonksiyonu için
using namespace std;

// Rakamları toplayan fonksiyon
int rakamToplami(int number) {
    number = abs(number);
    int sum = 0;

    while (number != 0) {
        sum += number % 10;  
        number /= 10;        
    }
    
    return sum;
}

int main() {
    int number;
    cout << "Bir sayi girin: ";
    cin >> number;

    // Fonksiyonu çağırarak sonucu yazdırıyoruz
    cout << "Rakamlarin toplami: " << rakamToplami(number) << endl;

    return 0;
}
