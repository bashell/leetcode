class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(i == 0 && j != 0)
                    grid[i][j] += grid[i][j-1];  // 位于第一行时，右边的元素仅仅依赖于左边的元素
                else if(i != 0 && j == 0)
                    grid[i][j] += grid[i-1][j];  // 位于第一列时，下边的元素仅仅依赖于上边的元素
                else
                    grid[i][j] += std::min(grid[i][j-1], grid[i-1][j]);
            }
        }
        return grid[m-1][n-1];
    }
};
