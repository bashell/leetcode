bool isPowerOfTwo(int n) {
    int count = 0;
    
    while(n > 0)    // ͳ��n�Ķ����Ʊ�ʾ��'1'�ĸ�����
    {
        if(n & 1)
            count++;
        n >>= 1;
    }
    if(count == 1)    // ��ֻ��һ��'1'����nΪ2����
        return true;
    else
        return false;
}