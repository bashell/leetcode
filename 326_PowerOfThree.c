// recursive version
bool isPowerOfThree(int n) {
    if(n < 1) return false;
    if(n == 1) return true;
    else return n % 3 == 0 && isPowerOfThree(n / 3);
}

// iterative version
bool isPowerOfThree(int n) {
    if(n > 1) {
        while(n % 3 == 0)
            n /= 3;
    }
    return n == 1;
}
