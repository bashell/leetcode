class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if(n == 0) return;
        for(auto &m : matrix)
            std::reverse(m.begin(), m.end());
        for(int i = 0; i < n - 1; ++i) {  // 按斜对角线进行元素交换
            for(int j = 0; j < n - 1 - i; ++j) {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[n-1-j][n-1-i];
                matrix[n-1-j][n-1-i] = tmp;
            }
        }
    }
};
