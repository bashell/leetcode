int hammingWeight(uint32_t n) {
    uint32_t temp = 1;
    int k;
    int result = n & temp;
    for(k = 1; k < 32; ++k)
    {
        temp <<= 1;
        if(n & temp)
            result++;
    }
        
    return result; 
}
