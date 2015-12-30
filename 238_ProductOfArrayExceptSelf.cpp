// two passes solution
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int sz = nums.size();
        vector<int> result(sz);
        int k = 1;
        for(int i = 0; i < sz; ++i) {  // pass one
            result[i] = k;
            k *= nums[i];
        }
        k = 1;
        for(int i = sz - 1; i >= 0; --i) {  // pass two
            result[i] *= k;
            k *= nums[i];
        }
        return result;
    }
};
