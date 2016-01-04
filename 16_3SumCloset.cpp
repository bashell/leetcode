class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.size() == 3) return std::accumulate(nums.cbegin(), nums.cend(), 0);
        std::sort(nums.begin(), nums.end());
        int n = nums.size();
        int diff_min = INT_MAX, sum_min = INT_MAX;
        for(int i = 0; i < n; ++i) {
            for(int j = i + 1, k = n - 1; j < k; ) {
                int sum_tmp = nums[i] + nums[j] + nums[k];
                if(sum_tmp == target)
                    return target;
                if(abs(sum_tmp - target) < diff_min) {
                    sum_min = sum_tmp;
                    diff_min = abs(sum_tmp - target);
                }
                sum_tmp < target ? ++j : --k;
            }
        }
        return sum_min;
    }
};
