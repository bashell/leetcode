// T(N) = O(N),  S(N) = O(1)
// 依次统计所有数在每一位上'1'的总数sum. (每个数每次只能在该位上贡献一个'1')
// 若sum为3的倍数, 说明单独出现的数没有在该位上贡献'1'; 否则将该位加入结果.
int singleNumber(int* nums, int numsSize) {
    int i, j, bi, res = 0;
    for(i = 0; i < 32; ++i) {  // 假设整型int为32位
        int sum = 0;
        bi = 1 << i;  // 记录当前位
        for(j = 0; j < numsSize; ++j)
            if(bi & nums[j])
                ++sum;
        if(sum % 3)
            res = res | bi;
    }
    return res;
}
