class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> iset1, iset2;
        iset1.insert(nums1.cbegin(), nums1.cend());
        iset2.insert(nums2.cbegin(), nums2.cend());
        vector<int> res;
        for(auto val : iset1)
            if(iset2.find(val) != iset2.end())
                res.push_back(val);
        return res;
    }
};
