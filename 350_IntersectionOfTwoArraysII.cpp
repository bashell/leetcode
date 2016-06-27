// Solution1: map
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

// Solution2: two pointers
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        if(nums1.size() == 0 || nums2.size() == 0) return res;
        std::sort(nums1.begin(), nums1.end());
        std::sort(nums2.begin(), nums2.end());
        int m = nums1.size(), n = nums2.size();
        for(int i = 0, j = 0; i < m && j < n; ) {
            if(nums1[i] == nums2[j]) {
                res.push_back(nums1[i]);
                ++i, ++j;
            } else if(nums1[i] < nums2[j]) {
                ++i;
            } else {
                ++j;
            }
        }
        return res;
    }
};
