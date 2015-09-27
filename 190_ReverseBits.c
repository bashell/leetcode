uint32_t reverseBits(uint32_t n) {
    int arr[32];
    int i, power;
    uint32_t result = 0;
    
    for(i = 31; i >= 0; i--)    // 将n的所有二进制位保存到数组中：二进制高位存于数组低位
    {
        arr[i] = n & 1;
        n >>= 1;
    }
    for(i = 0, power = 1; i < 32; i++)
    {
        result += arr[i] * power;
        power *= 2;
    }
    
    return result;
}
