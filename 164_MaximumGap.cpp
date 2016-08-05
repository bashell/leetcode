class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1) return 0;
        int max_gap = INT_MIN;
        std::sort(nums.begin(), nums.end());
        for(int i = 0; i < n-1; ++i) {
            int this_gap = nums[i+1] - nums[i];
            if(this_gap > max_gap)
                max_gap = this_gap;
        }
        return max_gap;
    }
};
