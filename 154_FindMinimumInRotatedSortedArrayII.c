// T(N) = O(N)
int findMin(int* nums, int numsSize) {
    if(numsSize == 1) return nums[0];
    int i;
    for(i = 1; i < numsSize && nums[i] >= nums[i-1]; ++i)
        ;
    if(i >= numsSize)
        return nums[0];
    else
        return nums[i];
}

// T(N) = O(logN)
int findMin(int* nums, int numsSize) {
    int lhs = 0, rhs = numsSize - 1, mid = 0;
    while(lhs < rhs) {
        mid = lhs + (rhs - lhs) / 2;
        if(nums[mid] > nums[rhs])
            lhs = mid + 1;
        else if(nums[mid] < nums[rhs])
            rhs = mid;
        else
            --rhs;
    }
    return nums[rhs];
}
