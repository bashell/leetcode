class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        string res("");
        if(n == 0) return res;
        int min_len = INT_MAX;
        for(const auto &s : strs) {
            int len_s = s.size();
            if(len_s < min_len)
                min_len = len_s;
        }
        for(int i = 0; i < min_len; ++i) {
            unordered_set<char> cset;
            for(const auto &s : strs) 
                cset.insert(s[i]);
            if(cset.size() == 1)  // all same
                res += strs[0][i];
            else
                break;  // at least one different from others
        }
        return res;
    }
};
