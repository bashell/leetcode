// T(n) = O(n), S(n) = O(n)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        int max_val = nums[0];
        for(int i = 1; i < n; ++i) {
            dp[i] = std::max(dp[i-1] + nums[i], nums[i]);
            max_val = std::max(max_val, dp[i]);
        }
        return max_val;
    }
};

// T(n) = O(n), S(n) = O(1)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        int max_sum = nums[0], this_sum = nums[0];
        for(int i = 1; i < n; ++i) {
            this_sum = std::max(this_sum + nums[i], nums[i]);
            max_sum = std::max(max_sum, this_sum);
        }
        return max_sum;
    }
};


