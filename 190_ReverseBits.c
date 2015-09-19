uint32_t reverseBits(uint32_t n) {
    int arr[32];
    int i, power;
    uint32_t result = 0;
    
    for(i = 31; i >= 0; i--)    // ��n�����ж�����λ���浽�����У������Ƹ�λ���������λ
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