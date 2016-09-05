class Solution {
public:
    // Tabulation: bottom-up
    // S(n) = O(n)
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> dp(triangle[n-1]);
        for(int i = n-2; i >= 0; --i)
            for(int j = 0; j <= i; ++j)
                dp[j] = triangle[i][j] + std::min(dp[j], dp[j+1]);
        return dp[0];
    }
};
