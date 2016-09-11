class Solution {
public:
    char findTheDifference(string s, string t) {
        int res = 0;
        for(auto ch : s)
            res ^= ch;
        for(auto ch : t)
            res ^= ch;
        return res;
    }
};
