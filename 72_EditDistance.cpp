class Solution {
public:
    // Buttom-Up table building
    int minDistanceHelper(string word1, string word2, int len1, int len2) {
        int dp[len1+1][len2+1] = {0};
        for(int i = 0; i <= len1; ++i) {
            for(int j = 0; j <= len2; ++j) {
                if(i == 0)
                    dp[0][j] = j;
                else if(j == 0)
                    dp[i][0] = i;
                else if(word1[i-1] == word2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = 1 + std::min(std::min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]);
            }
        }
        return dp[len1][len2];
    }
    
    int minDistance(string word1, string word2) {
        int len1 = word1.size(), len2 = word2.size();
        return minDistanceHelper(word1, word2, word1.size(), word2.size());
    }
};
