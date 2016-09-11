class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> hash(26, 0);
        for(auto ch : s)
            ++hash[ch-'a'];
        for(int i = 0; i < s.size(); ++i)
            if(hash[s[i]-'a'] == 1)
                return i;
        return -1;
    }
};
