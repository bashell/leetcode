int removeDuplicates(int* nums, int numsSize) {
    if(numsSize == 0)
        return 0;
    if(numsSize == 1)
        return 1;
        
    int i = 0, j = 1;
    while(1) {
        while(nums[j] == nums[i])
            ++j;
        if(j < numsSize)
            nums[++i] = nums[j];
        else
            break;
    }
    return i + 1;
}
