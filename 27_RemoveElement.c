int removeElement(int* nums, int numsSize, int val) {
    if(numsSize == 0)  return 0;
    int i = 0, j = numsSize - 1;
    while(i < j) {
        if(nums[i] == val)
            nums[i] = nums[j--];
        else
            i++;
    }
    
    // i == j时测试
    if(nums[i] == val)
        return i;
    else
        return i + 1;
}
