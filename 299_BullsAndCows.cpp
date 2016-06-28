class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0, cows = 0;
        // 1. calculate bulls
        for(int i = 0; i != secret.size(); ++i)
            if(secret[i] == guess[i])
                ++bulls;
        // 2. calculate the intersection of two string, allowing multi-value.
        unordered_map<char, int> imap;
        for(auto s : secret) ++imap[s];
        for(auto g : guess) {
            if(imap.find(g) != imap.end() && imap[g] > 0) {
                --imap[g];
                ++cows;
            }
        }
        return to_string(bulls) + "A" + to_string(cows-bulls) + "B";
    }
};
