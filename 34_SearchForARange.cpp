class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        if(n == 0 || target < nums[0] || target > nums[n-1]) 
            return vector<int>{-1, -1};
        vector<int> result;
        
        /* first pass */
        int left = 0, right = n - 1;
        while(left < right) {
            int mid = left + (right - left) / 2;  // when rounding off, mid is nearer to left
            if(nums[mid] >= target)
                right = mid;
            else
                left = mid + 1;
        }
        if(nums[left] != target)  // the target value doesn't exist
            return vector<int>{-1, -1};
        else
            result.push_back(left);  // begining position of given value
        
        /* second pass */
        left = 0, right = n - 1;
        while(left < right) {
            int mid = right - (right - left) / 2;  // when rounding off, mid is nearer to right
            if(nums[mid] <= target)
                left = mid;
            else
                right = mid - 1;
        }
        result.push_back(right);  // ending position of given value
        return result;
    }
};
