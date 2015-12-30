class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if(matrix.size() == 0) return;
        int row = matrix.size(), col = matrix[0].size();
        string str_row(row, '0'), str_col(col, '0');  // extra space: two string
        for(int i = 0; i < row; ++i) {
            for(int j = 0; j < col; ++j) {
                if(matrix[i][j] == 0) {
                    str_row[i] = '1';
                    str_col[j] = '1';
                }
            }
        }
        for(int i = 0; i < row; ++i) {
            if(str_row[i] == '1') {
                for(int j = 0; j < col; ++j)
                    matrix[i][j] = 0;
            }
        }
        for(int j = 0; j < col; ++j) {
            if(str_col[j] == '1') {
                for(int i = 0; i < row; ++i)
                    matrix[i][j] = 0;
            }
        }
    }
};
