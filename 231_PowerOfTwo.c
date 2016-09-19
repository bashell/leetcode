bool isPowerOfTwo(int n) {
    int count = 0;
    while(n > 0) {
        if(n & 1)
            ++count;
        n >>= 1;
    }
    return count == 1;
}


bool isPowerOfTwo(int n) {
    if(n <= 0) return false;
    int count = 0;
    while(n) {
        ++count;
        n = n&(n-1);
    }
    return count == 1;
}
