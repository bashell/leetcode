int singleNumber(int *nums, int numsSize)
{
	int temp = *nums;
	int *ptr = NULL;

    if(numsSize == 1)
		return temp;
    for(ptr = nums + 1; ptr < nums + numsSize; ++ptr)
		temp ^= *ptr;
	return temp;
}
