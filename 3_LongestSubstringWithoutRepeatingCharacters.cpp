class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> charIndex(256, -1);  // use a vector as hashTable
        int longest = 0, start = -1;
        for (int i = 0; i != s.length(); ++i) {
            if(charIndex[s[i]] > start)
                start = charIndex[s[i]];
            charIndex[s[i]] = i;
            longest = std::max(longest, i - start);
        }
        return longest;
    }
};
