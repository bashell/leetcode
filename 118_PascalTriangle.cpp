class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        if(numRows == 0)
            return res;
        res.push_back(vector<int>{1});
        if(numRows == 1)
            return res;
        res.push_back(vector<int>{1, 1});
        for(int row = 2; row < numRows; ++row) {
            vector<int> tmp;
            for(int i = 0; i < res[row-1].size() - 1; ++i) {
                tmp.push_back(res[row-1][i] + res[row-1][i+1]);
            }
            tmp.insert(tmp.begin(), 1);
            tmp.push_back(1);
            res.push_back(tmp);
        }
        return res;
    }
};
