int singleNumber(int* nums, int numsSize) {
    int i, res = 0;
    for(i = 0; i < numsSize; ++i)
        res ^= nums[i];
    return res;
}
