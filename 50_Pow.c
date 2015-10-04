// Solution1
double myPow(double x, int n) { 
    if(n == 0) 
        return 1;
    if(n < 0)
    {
        n = -n;
        x = 1 / x;
    }
    return n % 2 == 0 ? myPow(x * x, n >> 1) : x * myPow(x * x, n >> 1);
}

// Solution2
double myPow(double x, int n) { 
    if(n == 0) 
        return 1.0;
    double t = myPow(x, n / 2);
    if(n % 2) 
        return n < 0 ? 1 / x * t * t : x * t * t;
    else 
        return t * t;
}
