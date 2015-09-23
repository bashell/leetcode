class Solution{
    public:
        int missingNumber(vector<int>& nums){
            int misNum = 0, len = nums.size();
            for(int i = 0; i < len; ++i)
                misNum ^= i ^ nums[i];    // x与自身异或为0, x与0异或为x
            return misNum ^ len;
        }
};
