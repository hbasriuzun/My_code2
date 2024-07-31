class Solution {
public:
    double largestSumOfAverages(vector<int>& A, int K)
    {
        int n = A.size();
        vector<vector<double>> dp(K, vector<double>(n, 0.0));
        
        double now = 0.0;
        for(int i = 0; i<n; i++){now += (double)A[i]; dp[0][i] = now/(i+1);}
        
        for(int i = 1; i<K; i++)
            for(int j = i; j<n; j++)
            {
                dp[i][j] = dp[i-1][j-1] + (double)A[j];
                
                double now = (double)A[j];
                
                for(int k = j-1; k>=i; k--)
                {
                    now += (double)A[k];
                    dp[i][j] = max(dp[i][j], dp[i-1][k-1] + (now/(j-k+1)));
                }
            }
        
        return dp[K-1][n-1];
    }
};