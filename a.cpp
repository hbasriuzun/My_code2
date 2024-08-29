#include <iostream>
#include <cstdlib> // srand, rand için gerekli
#include <ctime>   // time için gerekli
#include <vector>
#include <algorithm> // std::swap için gerekli

// Bubble Sort algoritmasını tanımla
void bubbleSort(std::vector<std::pair<int, int>>& vec) {
    int n = vec.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (vec[j].second < vec[j + 1].second) {
                // Değerleri takas et
                std::swap(vec[j], vec[j + 1]);
            }
        }
    }
}

int main() {
    srand(time(0)); // Rastgele sayı üreteciyi saati temel alarak başlat

    int numTrials = 10000000; // Deneme sayısı
    double initialBet = 10.0; // İlk bahis miktarı
    double totalMoney = 1000000.0; // Başlangıçtaki toplam para
    int maxRounds = 100; // Bir oyunda maksimum tur sayısı

    std::vector<int> roundsToBankruptcy(maxRounds + 1, 0); // Her turda kaç kez iflas edildiğini tutar

    for (int trial = 0; trial < numTrials; ++trial) {
        double currentBet = initialBet;
        double money = totalMoney;
        int round = 0;

        while (money > 0 && round < maxRounds) {
            bool won = rand() % 2 == 0; // %50 şansla kazanma durumu

            if (won) {
                money += currentBet;
            } else {
                money -= currentBet;
                currentBet *= 2; // Bahsi ikiye katla
            }

            ++round;
        }

        if (money <= 0) {
            // Eğer para biterse, hangi turda iflas edildiğini kaydediyoruz
            roundsToBankruptcy[round]++;
        }
    }

    // Bubble Sort ile iflas sayılarını büyükten küçüğe sırala
    std::vector<std::pair<int, int>> roundBankruptcy;
    for (int i = 0; i <= maxRounds; ++i) {
        if (roundsToBankruptcy[i] > 0) {
            roundBankruptcy.emplace_back(i, roundsToBankruptcy[i]);
        }
    }

    bubbleSort(roundBankruptcy);

    // Sonuçları yazdırma
    std::cout << "Hangi raundda kac kere iflas ettiginin ozeti (büyükten küçüğe sıralı):" << std::endl;
    for (const auto& entry : roundBankruptcy) {
        std::cout << entry.first << ". raundda: " << entry.second << " kere iflas" << std::endl;
    }

    return 0;
}
