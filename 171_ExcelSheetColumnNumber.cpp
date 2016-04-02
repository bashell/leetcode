class Solution {
public:
    int titleToNumber(string s) {
        int num = 0;
        for(auto c : s) {
            num *= 26;    // 26进制：每左移一位，都乘以26
            num += (c - 'A') + 1;
        }
        return num;
    }
};
