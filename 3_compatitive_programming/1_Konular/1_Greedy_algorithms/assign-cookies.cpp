class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int ans = 0;

        if (g.size() == 0 || s.size() == 0)
            return 0;

        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int gi = 0;
        int si = 0;
        for (auto child : g) {
            while (s[si] < child) {
                si++;
                // uygun kurabiye yoksa devam et
                if (si >= s.size()) //kurabiyeler bitti
                    return ans;
            }
            // uygun çocuk için uygun kurabiye bulundu
            si++;
            ans++;

            if (si >= s.size()) //kurabiyeler bitti
                return ans;
        }

        return ans;
    }
};