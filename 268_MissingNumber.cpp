class Solution{
public:
    int missingNumber(vector<int>& nums) {
        int misNum = 0, len = nums.size();
        for(int i = 0; i < len; ++i)
            misNum ^= i ^ nums[i];    // x ^ x = 0, x ^ 0 = x
        return misNum ^ len;
    }
};
