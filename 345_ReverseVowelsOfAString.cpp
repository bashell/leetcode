class Solution {
public:
    string reverseVowels(string s) {
        unordered_set<char> cset{'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int i = 0, j = s.size()-1;
        while(1) {
            while(cset.find(s[i]) == cset.end())
                ++i;
            while(cset.find(s[j]) == cset.end())
                --j;
            if(i >= j)
                break;
            else {
                char tmp = s[i];
                s[i] = s[j];
                s[j] = tmp;
                ++i, --j;
            }
        }
        return s;
    }
};
