#include <iostream>
#include <bitset>
#include <iomanip>

using namespace std;

int fonk(int x);
int fonk2(int x);
int fonk3(int x){
    x=5;
    int y=6;
    char t = 'a';
    cout << x << endl;
    return t;
}

int main() {
    int n = 78;
    long long b = 21342142342123213;

    cout << left << setw(20) << 57 << "'in 0 ve 1 olarak değeri: ";
    cout << bitset<32>(57) << endl;

    cout << left << setw(20) << 30 << "'in 0 ve 1 olarak değeri: ";
    cout << bitset<64>(30) << endl;

    cout << left << setw(20) << 25 << "'in 0 ve 1 olarak değeri: ";
    cout << bitset<32>(25) << endl;

    cout << left << setw(20) << 89 << "'in 0 ve 1 olarak değeri: ";
    cout << bitset<32>(89) << endl;
    fonk(5);
    array<bool, 500> arr;
    
    return 0;
}

int fonk(int x) {
    return x;
    fonk2(x);
}
int fonk2(int x) {
    return x;

}