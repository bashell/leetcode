class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        if(n == 0) 
            return 0;
        vector<int> bit_vec, res;
        for(const auto &w : words) {
            int tmp = 0;
            for(auto c : w)
                tmp |= 1 << (c - 'a');
            bit_vec.push_back(tmp);
        }
        int max = 0;
        for(int i = 0; i < n - 1; ++i)
            for(int j = i + 1; j < n; ++j)
                if((bit_vec[i] & bit_vec[j]) == 0 && words[i].size() * words[j].size() > max)
                    max = words[i].size() * words[j].size();
        return max;
    }
};
