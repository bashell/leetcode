class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        if(nums.size() < 3) return result;
        sort(nums.begin(), nums.end());
        int sz = nums.size();
        for(int i = 0; i < sz; ++i) {
            if(i > 0 && nums[i] == nums[i - 1]) continue;  // ignore same ones
            int target = -nums[i];
            for(int j = i + 1, k = sz - 1; j < k; ) {
                if(nums[j] + nums[k] == target) {
                    vector<int> tmp{nums[i], nums[j], nums[k]};
                    result.push_back(tmp);
                    while(j < k && nums[j] == nums[j + 1]) ++j;  // ignore same ones
                    while(j < k && nums[k] == nums[k - 1]) --k;  // ignore same ones
                    ++j, --k;
                } else if(nums[j] + nums[k] < target) {
                    ++j;
                } else {
                    --k;
                }
            }
        }
        return result;
    }
};
