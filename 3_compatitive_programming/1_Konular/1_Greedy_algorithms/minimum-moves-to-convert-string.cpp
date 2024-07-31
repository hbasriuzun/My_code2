class Solution {
public:
    int minimumMoves(string s) {
        int i = 0, n = s.length(), count = 0;
        while (i < n) {
            if (s[i] == 'O')  
            // Eğer 0'a denk gelirsek devam ediyoruz
                i++;
            else
                count++, i += 3;  
                // Eğer X'e denk gelirsek 3 arttırıyoruz
        }
        return count;
    }
};