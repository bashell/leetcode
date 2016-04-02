class Solution {
public:
    string convertToTitle(int n) {
        string str;
        for( ; n > 0; n /= 26) {
            --n;
            str = (char)('A' + n % 26) + str;    // 字符是从右向左获得
        }
        return str;
    }
};
