#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int spaceoptimise(string& word1, string& word2) {
        vector<int> curr(word2.length() + 1, 0);
        vector<int> next(word2.length() + 1, 0);
        
        // 'next' vektörünü doldur
        for (int j = 0; j < word2.length(); j++)
            next[j] = word2.length() - j;
        
        // Birinci kelimenin karakterlerini tersten işle
        for (int i = word1.length() - 1; i >= 0; i--) {
            curr[word2.length()] = word1.length() - i;
            
            // İkinci kelimenin karakterlerini tersten işle
            for (int j = word2.length() - 1; j >= 0; j--) {
                int ans = 0;
                if (word1[i] == word2[j]) {
                    ans = next[j + 1]; // Karakterler eşleşiyor, işlem gerekmez
                } else {
                    int replaced = 1 + next[j + 1];
                    int deleted = 1 + next[j];
                    int inserted = 1 + curr[j + 1];
                    ans = min(replaced, min(deleted, inserted)); // Minimum maliyeti seç
                }
                curr[j] = ans; // Geçerli hücreyi minimum maliyetle güncelle
            }
            next = curr; // Bir sonraki satıra geç
        }
        return next[0]; // Minimum düzenleme mesafesi next[0]'da saklanır
    }

    int minDistance(string word1, string word2) {
        if (word1.length() == 0)
            return word2.length();
        if (word2.length() == 0)
            return word1.length();
        return spaceoptimise(word1, word2); // Optimizasyon fonksiyonunu çağır
    }
};

int main() {
    Solution solution;
    string word1 = "horse";
    string word2 = "ros";

    int result = solution.minDistance(word1, word2);
    cout << "The minimum edit distance between \"" << word1 << "\" and \"" << word2 << "\" is: " << result << endl;

    return 0;
}
