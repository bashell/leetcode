int singleNumber(int *nums, int numsSize)
{
	int temp = *nums;
	int *ptr;

    if(numsSize == 1)
		return temp;
	else
	{
		for(ptr = nums + 1; ptr < nums + numsSize; ++ptr)
			temp ^= *ptr;
		return temp;
	}
}