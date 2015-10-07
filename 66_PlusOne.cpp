class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for(int i = digits.size() - 1; i >= 0; --i) {
            if(digits[i] < 9) {
                ++digits[i];
                return digits;
            }
            digits[i] = 0;
        }
        // 若执行到此步, 则vector中所有数位都得到进位
        digits.insert(digits.begin(), 1);
        return digits;
    }
};
