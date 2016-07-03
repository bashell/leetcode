class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n, 0);
        dp[0] = 1;
        int f2 = 0, f3 = 0, f5 = 0;  // factor 2, 3, 5
        for(int i = 1; i < n; ++i) {
            dp[i] = std::min(std::min(dp[f2]*2, dp[f3]*3), dp[f5]*5);
            if(dp[i] == dp[f2]*2) ++f2;
            if(dp[i] == dp[f3]*3) ++f3;
            if(dp[i] == dp[f5]*5) ++f5;
        }
        return dp[n-1];
    }
};
