int removeDuplicates(int* nums, int numsSize) {
    if(numsSize == 0)
        return 0;
    if(numsSize == 1)
        return 1;
        
    int i, j;
    for(i = 0, j = 1; j < numsSize; ) {
        while(nums[j] == nums[i])
            ++j;
        if(j < numsSize)
            nums[++i] = nums[j];
    }
    return i + 1;
}
