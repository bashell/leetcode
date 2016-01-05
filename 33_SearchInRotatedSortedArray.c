int search(int* nums, int numsSize, int target) {
    int start = 0, end = numsSize - 1;
    while(start <= end) {
        int mid = start + (end - start) / 2;
        if(target == nums[mid])
            return mid;
        if(nums[start] <= nums[mid]) {  // left part remains sorted
            if(target >= nums[start] && target < nums[mid])  // target belongs to the left part
                end = mid - 1;
            else  // target belongs to the right part
                start = mid + 1;
        }
        else if(nums[mid] <= nums[end]) {  // right part remains sorted
            if(target > nums[mid] && target <= nums[end])  // target belongs to the right part
                start = mid + 1;
            else  // target belongs to the left part
                end = mid - 1;
        }
    }
    return -1;
}
