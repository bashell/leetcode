bool isPowerOfTwo(int n) {
    int count = 0;
    
    while(n > 0)    // 统计n的二进制表示中'1'的个数。
    {
        if(n & 1)
            count++;
        n >>= 1;
    }
    if(count == 1)    // 若只有一个'1'，则n为2的幂
        return true;
    else
        return false;
}