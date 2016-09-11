class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> hash(26, 0);
        for(auto ch : magazine)
            ++hash[ch-'a'];
        for(auto ch : ransomNote)
            --hash[ch-'a'];
        for(auto i : hash)
            if(i < 0) return false;
        return true;
    }
};
