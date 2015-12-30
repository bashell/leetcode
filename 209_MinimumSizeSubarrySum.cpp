// dynamic sliding window method:  O(N)
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size();  // vector's size
        int res = INT_MAX;  // preserve the result
        int i = 0, j = 0, sum = 0;
        while(j < n) {
            while(j < n && sum < s)  // right side expand by several elements
                sum += nums[j++];
            /* sum is no less than s now */
            while(sum >= s) {  // left side shrink by several elements
                res = min(res, j - i);  // update if necessary
                sum -= nums[i++];
            }
        }
        return res == INT_MAX ? 0 : res;
    }
};
