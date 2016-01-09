int removeDuplicates(int* nums, int numsSize) {
    if(numsSize == 0) return 0;
    if(numsSize == 1) return 1;
    int i = 0, j = 0;
    while(1) {
        ++j;
        if(j < numsSize && nums[j] == nums[i])  // duplicates are allowed at most twice
            nums[++i] = nums[j++];
        while(j < numsSize && nums[j] == nums[i])  // ignore remaining duplicates if exist
            ++j;
        if(j < numsSize)
            nums[++i] = nums[j];
        else
            break;
    }
    return i + 1;
}
