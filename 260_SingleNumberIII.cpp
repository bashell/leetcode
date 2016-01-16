class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xor_tmp = 0;
        for(auto n : nums)  // xor_tmp保存 a^b
            xor_tmp ^= n;
        int bi = 1;
        while((xor_tmp & bi) == 0)  // 优先级: '==' > '&'
            bi <<= 1;
        // while结束后, bi记录a与b第一个不同的位(from right to left)
        int res_a = 0, res_b = 0;
        for(auto n : nums)  // 按照bi将nums中的元素分成两组
            if((bi & n) == 0)
                res_a ^= n;
            else
                res_b ^= n;
        return {res_a, res_b};
    }
};
