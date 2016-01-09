bool isPalindrome(int x) {
    if(x < 0) return false;
    if(x >= 0 && x < 10) return true;
    int k1 = x, k2 = 0;
    while(k1 > 0) {
        k2 = k2 * 10 + k1 % 10;
        k1 /= 10;
    }
    return x == k2;
}
