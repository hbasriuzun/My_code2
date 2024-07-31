#include <iostream>
#include <bitset> // Bitset kullanmak için gerekli kütüphane
#include <iomanip> // setw() ve left kullanmak için gerekli kütüphane
#include <vector>

using namespace std;


int main() {
    vector<int> nums = {4,1,2,1,2};

    int a=0,s=nums.size();
    cout << "eger iki aynı sayı ^ işlemine sokulursa 0 olur. ÖR: \n";
    cout << "39 ^ 39 = " << (39^39) << endl;
    cout << "39" << " bit değeri " << bitset<32>(39) << endl;
    cout << endl;
    for(auto x:nums){
        cout << "a:" << a << " bit değeri " << bitset<32>(a) << endl;
        cout << "x:" << x << " bit değeri " << bitset<32>(x) << endl;
        a^=x;
        cout << endl;
    }
    return 0;
}
