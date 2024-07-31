#include <iostream>
#include <bitset>
#include <iomanip>

using namespace std;

int main() {
    // Örnek değişkenler
    int x = 5;  // 00000000000000000000000000000101 (2'lik tabanda)
    int y = 3;  // 00000000000000000000000000000011 (2'lik tabanda)
    int result;

    cout << left << setw(2) << x << "'in bitsel değeri: ";
    cout << bitset<32>(x) << endl;

    cout << left << setw(2) << y << "'ün bitsel değeri: ";
    cout << bitset<32>(y) << endl;
    cout << "\n";

    // AND operatörü ( & )
    result = x & y; // x ve y'nin her iki pozisyonunda da 1 varsa sonuç 1 olur
    cout << "x & y = " << result << endl; // Çıktı: 00000000000000000000000000000001 (2'lik tabanda) => 1 (10'luk tabanda)
    cout << bitset<32>(x) << endl;
    cout << bitset<32>(y) << endl;
    cout << bitset<32>(result) << endl;
    cout << "\n";

    // OR operatörü ( | )
    result = x | y; // x veya y'nin herhangi bir pozisyonunda 1 varsa sonuç 1 olur
    cout << "x | y = " << result << endl; // Çıktı: 00000000000000000000000000000111 (2'lik tabanda) => 7 (10'luk tabanda)
    cout << bitset<32>(x) << endl;
    cout << bitset<32>(y) << endl;
    cout << bitset<32>(result) << endl;
    cout << "\n";
    
    // XOR operatörü ( ^ )
    result = x ^ y; // x veya y'nin fakat her ikisinde birden 1 varsa sonuç 1 olur
    cout << "x ^ y = " << result << endl; // Çıktı: 00000000000000000000000000000110 (2'lik tabanda) => 6 (10'luk tabanda)
    cout << bitset<32>(x) << endl;
    cout << bitset<32>(y) << endl;
    cout << bitset<32>(result) << endl;
    cout << "\n";
    
    // NOT operatörü ( ~ )
    result = ~x; // x'in her biti tersine çevrilir (0'lar 1'e, 1'ler 0'a dönüşür)
    cout << "~x = " << result << endl; // Çıktı: 11111111111111111111111111111010 (2'lik tabanda) => -6 (10'luk tabanda)
    cout << bitset<32>(x) << endl;
    cout << bitset<32>(result) << endl;
    cout << "\n";
    
    vector<int> nums = {4,1,2,1,2};

    
    return 0;
}
