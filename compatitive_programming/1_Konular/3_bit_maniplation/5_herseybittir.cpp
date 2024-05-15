#include <iostream>
#include <bitset>
#include <iomanip>

using namespace std;

int main() {
    int n = 78;
    long long b = 21342142342123213;

    cout << left << setw(20) << n << "'in 0 ve 1 olarak değeri: ";
    cout << bitset<32>(n) << endl;

    cout << left << setw(20) << b << "'ün 0 ve 1 olarak değeri: ";
    cout << bitset<64>(b) << endl;

    cout << left << setw(20) << n << "'in bit olarak kapladığı alan: ";
    cout << sizeof(n) << endl;

    cout << left << setw(20) << b << "'ün bit olarak kapladığı alan: ";
    cout << sizeof(b) << endl;


    cout << left << setw(20) << b << "'ün bit olarak kapladığı alan: ";
    cout << left << setw(20) << b << "'ün bit olarak kapladığı alan: ";
    cout << left << setw(20) << b << "'ün bit olarak kapladığı alan: ";
    cout << left << setw(20) << b << "'ün bit olarak kapladığı alan: ";

     cout << left << setw(20) << 34 << "'ün bit olarak kapladığı alan: ";
    cout << sizeof(34) << endl;
       cout << left << setw(20) << 20 << "'ün bit olarak kapladığı alan: ";
    cout << sizeof(20) << endl;
         cout << left << setw(20) << 67 << "'ün bit olarak kapladığı alan: ";
    cout << sizeof(67) << endl;
         cout << left << setw(20) << 57 << "'ün bit olarak kapladığı alan: ";
    cout << sizeof(57) << endl;



    return 0;
}
