class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        if(nums1.size() == 0 || nums2.size() == 0) return res;
        unordered_map<int, int> imap;
        for(auto i : nums1) ++imap[i];
        for(auto i : nums2) {
            if(imap.find(i) != imap.end() && imap[i] > 0) {
                --imap[i];
                res.push_back(i);
            }
        }
        return res;
    }
};
