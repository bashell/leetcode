class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        int carry = 0;    // 进位标志
        int index_a = a.size() - 1, index_b = b.size() - 1;    // 遍历索引
        for( ; index_a >=0 || index_b >= 0; --index_a, --index_b) {
            int temp_a = index_a >= 0 ? a[index_a] - '0' : 0;
            int temp_b = index_b >= 0 ? b[index_b] - '0' : 0;
            int cur = carry + temp_a + temp_b;
            res.insert(res.begin(), cur % 2 + '0');    // 头部插入
            carry = cur / 2;    // 更新进位标志
        }
        // 循环结束后再判断一次是否发生进位
        if(carry)
            res.insert(res.begin(), carry + '0');
        return res;
    }
};
