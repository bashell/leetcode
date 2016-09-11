class Solution {
public:
    int getSum(int a, int b) {
        while(0 != b) {
            int tmp = a ^ b;  // 求和不进位
            b = (a & b) << 1; // 考虑进位值
            a = tmp;
        }
        return a;
    }
};
