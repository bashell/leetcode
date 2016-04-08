class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        string res("");
        vector<vector<char>> rows(numRows, vector<char>{});
        int n = s.size();
        int flag = 1, cnt = 0;
        for(int i = 0; i < n; ++i) {
            if(flag) {  // down
                rows[cnt].push_back(s[i]);
                ++cnt;
                if(cnt == numRows - 1)
                    flag = 0;
            } else {  // up
                rows[cnt].push_back(s[i]);
                --cnt;
                if(cnt == 0)
                    flag = 1;
            }
        }
        for(const auto &r : rows)
            for(const auto c : r)
                res += c;
        return res;
    }
};
