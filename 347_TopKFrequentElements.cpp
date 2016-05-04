class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> umap;
        for(auto n : nums)
            ++umap[n];
        multimap<int, int> mmap;
        for(auto u : umap)
            mmap.insert({u.second, u.first});
        vector<int> res;
        auto iter = mmap.end();
        for(int i = 0; i < k; ++i) {
            --iter;
            res.push_back(iter->second);
        }
        return res;
    }
};
