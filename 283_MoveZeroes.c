void moveZeroes(int *nums, int numsSize)
{
    int i, j, temp;
    
    for(i = 0, j = 0; j < numsSize ; )
    {
        while(nums[i] != 0)    // 到达第一个0处
            i++;
        while(nums[j] == 0)    // 到达第一个非0处
            j++;
        if(i >= numsSize || j >= numsSize)    // 退出条件
            break;
        if(i < j)    // 若第一个0在第一个非0前面, 则进行交换
        {
            temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
        }else    // 若第一个非0在第一个0前面, 则不需要处理这个非0值
        {
            j++;
        }
    }
}
