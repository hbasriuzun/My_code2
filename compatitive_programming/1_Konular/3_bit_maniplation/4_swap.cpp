#include <iostream>
using namespace std;

// İki tamsayıyı yer değiştiren bir fonksiyon tanımlanıyor.
void swap(int &x, int &y)
{
    // Eğer x ve y farklıysa (değerleri birbirinden farklıysa)
    if (x != y)
    {
        // XOR işlemi kullanılarak değerler yer değiştiriliyor.
        x = x ^ y;  // x, x ve y'nin XOR'lanmasıyla elde edilen değere atanıyor.
        y = x ^ y;  // y, x (şu anda XOR işlemi uygulanmış olan x) ve orijinal y'nin XOR'lanmasıyla elde edilen değere atanıyor.
        x = x ^ y;  // x, orijinal x ve şu anda XOR işlemi uygulanmış olan y'nin XOR'lanmasıyla elde edilen değere atanıyor.
    }
}

int main()
{
    int x = 3, y = 4;

    // Değiştirilmeden önce x ve y'nin değerleri ekrana yazdırılıyor.
    cout << "Değiştirilmeden önce: x = " << x << " ve y = " << y;

    // takas fonksiyonu çağrılarak x ve y'nin değerleri değiştiriliyor.
    swap(x, y);

    // Değiştirildikten sonra x ve y'nin yeni değerleri ekrana yazdırılıyor.
    cout << "\nDeğiştirildikten sonra: x = " << x << " ve y = " << y;

    return 0;
}
