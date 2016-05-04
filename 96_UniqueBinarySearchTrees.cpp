/*

             root: #0           root: #1           root: #2              root: #n-1            root: #n
             /     \            /      \            /     \               /      \            /       \
          left:0  right:n-1  left:1  right:n-2   left:2  right:n-3     left:n-2  right:1   left:n-1  right:0
          
   F(n) = F(0) * F(n-1)   +   F(1) * F(n-2) +   F(2) * F(n-3) + ... + F(n-2) * F(1)   +     F(n-1) * F(0)
   
*/

class Solution {
public:
    int numTrees(int n) {
        int dp[n+1];
        dp[0] = dp[1] = 1;  // base case
        for(int i = 2; i <= n; ++i) {
            for(int j = 1; j <= i; ++j) {
                dp[i] += dp[j-1] * dp[i-j];
            }
        }
        return dp[n];
    }
};
