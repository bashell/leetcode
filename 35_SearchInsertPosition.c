int searchHelper(int *nums, int target, int left, int right) {
    if(left == right)
        return left;
    int mid = left + (right - left) / 2;
    if(target <= nums[mid])
        return searchHelper(nums, target, left, mid);
    else
        return searchHelper(nums, target, mid + 1, right);
}

// Binary Search
int searchInsert(int* nums, int numsSize, int target) {
    return searchHelper(nums, target, 0, numsSize);
}
