void merge(int* nums1, int m, int* nums2, int n) {
    int i = m - 1, j = n - 1, k = m + n - 1;
    while(i >= 0 && j >= 0) {
        if(nums1[i] > nums2[j])
            nums1[k--] = nums1[i--];
        else
            nums1[k--] = nums2[j--];
    }
    // 数组nums2耗尽时，nums1剩余的元素不需要操作，已经有序
    // 数组nums1耗尽时, 继续复制nums2的剩余元素
    while(j >= 0)
        nums1[k--] = nums2[j--];
}
