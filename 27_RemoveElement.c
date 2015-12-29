int removeElement(int* nums, int numsSize, int val) {
    if(numsSize == 0)  return 0;
    int i = 0, j = numsSize - 1;
    while(i < j) {
        if(nums[i] == val)
            nums[i] = nums[j--];
        else
            i++;
    }
    return nums[i] == val ? i : i + 1;    
}
