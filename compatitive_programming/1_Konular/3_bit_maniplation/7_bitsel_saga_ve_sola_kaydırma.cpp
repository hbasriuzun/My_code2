#include <iostream>
#include <bitset> // Bitset kullanmak için gerekli kütüphane
#include <iomanip> // setw() ve left kullanmak için gerekli kütüphane

using namespace std;

int main() {
    int x = 5; // 00000000000000000000000000000101 (2'lik tabanda)
    int y = 3; // 00000000000000000000000000000011 (2'lik tabanda)
    int result;

    cout << left << setw(2) << x << "'in bitsel değeri: ";
    cout << bitset<32>(x) << endl;

    cout << left << setw(2) << y << "'ün bitsel değeri: ";
    cout << bitset<32>(y) << endl;
    cout << "\n";

    // Bitsel sağa kaydırma operatörü ( >> )
    
    result = x >> 1; // x'in tüm bitlerini bir sağa kaydırır
    cout << "result = x >> 1 = " << bitset<32>(result) << endl; // Sonucun 32 bitlik binary temsilini gösterir
    cout << "result = " << result << endl; // Sonucu onluk tabanda gösterir
    cout << "\n";

    // Bitsel sola kaydırma operatörü ( << )
    result = y << 2; // y'nin tüm bitlerini iki sola kaydırır
    cout << "result = y << 2 = " << bitset<32>(result) << endl; // Sonucun 32 bitlik binary temsilini gösterir
    cout << "result = " << result << endl; // Sonucu onluk tabanda gösterir
    cout << "\n";

    // Bitsel sağa kaydırma ve atama operatörü ( >>= )
    x >>= 1; // x'in tüm bitlerini bir sağa kaydırır ve sonucu x'e atar
    cout << "x >>= 1: " << bitset<32>(x) << endl; // x'in 32 bitlik binary temsilini gösterir
    cout << "x = " << x << endl; // x'in onluk tabandaki değerini gösterir
    cout << "\n";

    // Bitsel sola kaydırma ve atama operatörü ( <<= )
    y <<= 2; // y'nin tüm bitlerini iki sola kaydırır ve sonucu y'e atar
    cout << "y <<= 2: " << bitset<32>(y) << endl; // y'nin 32 bitlik binary temsilini gösterir
    cout << "y = " << y << endl; // y'nin onluk tabandaki değerini gösterir
    cout << "\n";

    return 0;
}
