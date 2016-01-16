// Solution1: T(N) = O(N)
class Solution{
public:
    int missingNumber(vector<int>& nums) {
        int misNum = 0, len = nums.size();
        for(int i = 0; i < len; ++i)
            misNum ^= i ^ nums[i];    // x ^ x = 0, x ^ 0 = x
        return misNum ^ len;
    }
};

// Solution2: T(N) = O(NlogN) + O(logN) = O(NlogN)
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int left = 0, right = nums.size() - 1;
        while(left < right) {
            int mid = left + (right - left) / 2;
            if(nums[mid] == mid)  // nums[mid] 一定大于等于 mid
                left = mid + 1;
            else
                right = mid - 1;
        }
        return nums[left] == left ? left + 1 : left;
    }
};
