class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<char> st_vec(128, 0), ts_vec(128, 0);
        int n = s.size();
        for(int i = 0; i < n; ++i) {
            if(st_vec[s[i]] == 0 && ts_vec[t[i]] == 0) {
                st_vec[s[i]] = t[i];
                ts_vec[t[i]] = s[i];
            } else {
                if(st_vec[s[i]] != t[i] || ts_vec[t[i]] != s[i])
                    return false;
            }
        }
        return true;
    }
};
