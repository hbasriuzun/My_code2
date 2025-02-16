class Solution {
public:
    // s: i*i'nin string karşılığı
    // index: şimdiki konum
    // target: hala toplanması gereken değer (i'den geriye kalan)
    bool canPartition(const string &s, int index, int target) {
        // Eğer stringin sonuna geldiysek, ve hala toplanması gereken hedef 0 ise
        if (index == s.size()) {
            return (target == 0);
        }
        
        // Fazladan optimizasyon: Eğer target < 0 olduysa direkt başarısız dönebiliriz
        if (target < 0) return false;

        // Alt substringleri deneyerek ilerle
        long val = 0;
        for (int i = index; i < (int)s.size(); i++) {
            // Rakamları teker teker ekleyerek val oluşturuyoruz
            val = val * 10 + (s[i] - '0'); 
            
            // Eğer val > target ise daha fazla büyütmenin anlamı yok
            if (val > target) break;

            // Kalan parçayı (i+1) ve (target - val) şeklinde kontrol et
            if (canPartition(s, i + 1, target - val)) {
                return true;
            }
        }
        return false;
    }

    int punishmentNumber(int n) {
        long long answer = 0;

        for(int i = 1; i <= n; i++){
            long long sq = (long long)i * i;  
            string strSq = to_string(sq);

            // Eğer i*i'yi oluşturan stringi (strSq) parçalara ayırarak topladığımızda i'yi elde edebiliyorsak
            if(canPartition(strSq, 0, i)){
                answer += sq;
            }
        }
        return (int)answer;
    }
};
