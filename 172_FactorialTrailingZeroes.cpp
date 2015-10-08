class Solution {
public:
    // 2 * 5 = 10, 阶乘中2多5少, 故每出现一个5就多一个trailing 0.
    // 对于25 = 5 * 5, 125 = 5 * 5 * 5, ... 分别贡献了2个、3个5
    // 故只需计算所有 n/5, n/25, n/125, ... 的出现次数即可(计算n/5时, 分别包含了一次计算n/25, n/125, ...)
    int trailingZeroes(int n) {
        int zeroNums = n / 5;
        while(n /= 5)
            zeroNums += n / 5;
        return zeroNums;
    }
};
