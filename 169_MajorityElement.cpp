// Solution1
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        return nums[nums.size()/2];
    }
};

// Solution2
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> imap;
        for(auto i : nums)
            ++imap[i];
        int cnt = nums.size() / 2;
        for(auto i : imap)
            if(i.second > cnt)
                return i.first;
    }
};
