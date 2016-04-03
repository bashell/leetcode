class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        int dp[m][n] = {0};
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(obstacleGrid[i][j] == 1) {  // 障碍所在
                    dp[i][j] = 0;
                    continue;
                }
                if(i == 0 && j == 0)
                    dp[i][j] = 1;
                else if(i == 0 && j != 0) {  // 第一行，右边仅仅依赖左边
                    dp[i][j] = dp[i][j-1];
                }
                else if(i != 0 && j == 0) {  // 第一列，下边仅仅依赖上边
                    dp[i][j] = dp[i-1][j];
                }
                else if(i != 0 && j != 0) {
                    if(obstacleGrid[i-1][j] == 1 && obstacleGrid[i][j-1] == 1)  // 完全封死
                        dp[i][j] = 0;
                    else if(obstacleGrid[i-1][j] == 1 && obstacleGrid[i][j-1] == 0)  // 上边有入口
                        dp[i][j] = dp[i][j-1];
                    else if(obstacleGrid[i-1][j] == 0 && obstacleGrid[i][j-1] == 1)  // 左边有入口
                        dp[i][j] = dp[i-1][j];
                    else
                        dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }
        return dp[m-1][n-1];
    }
};
