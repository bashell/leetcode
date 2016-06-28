class Solution {
public:
    bool wordPattern(string pattern, string str) {
        vector<string> svec;
        unordered_map<char, string> umap;
        unordered_set<char> key_set;
        unordered_set<string> val_set;
        string tmp;
        istringstream iss(str);
        while(iss >> tmp)
            svec.push_back(tmp);
        int p_len = pattern.size(), s_len = svec.size();
        if(p_len != s_len) return false;
        for(int i = 0; i != p_len; ++i) {
            if(umap.find(pattern[i]) == umap.end()) {
                umap[pattern[i]] = svec[i];
                key_set.insert(pattern[i]);
                val_set.insert(svec[i]);
                if(key_set.size() != val_set.size())  // "ab" : "dog dog"
                    return false;
            } else {
                if(umap[pattern[i]] != svec[i])  // "aa" : "cat dog"
                    return false;
            }
        }
        return true;
    }
};
