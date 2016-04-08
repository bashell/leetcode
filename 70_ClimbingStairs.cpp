class Solution {
public:
    // 设爬n层梯子有f(n)种方法,则f(n) = f(n-1) + f(n-2). 
    // Note: f(n-1)再爬1 step即可,f(n-2)再爬2 steps即可.
    // Fibonacci: f(1) = f(2) = 1
    int climbStairs(int n) {
        if(n <= 2)
            return n;
        int a = 1, b = 1, c;
        for(int i = 2; i < n; ++i) {
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }
};
