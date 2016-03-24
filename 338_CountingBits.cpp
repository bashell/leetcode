/*
 DP (Bottom Up)
 0 1 | 1 2 | 1 2 2 3 | 0 2 2 3 2 3 3 4 | ... 
*/

// Solution1: O(NlogN)
// N: num  
// logN: num的二进制位数

class Solution {
public:
    vector<int> countBits(int num) {
        if(num == 0) return vector<int>{0};
        if(num == 1) return vector<int>{0, 1};
        vector<int> res{0, 1};

        int bit_len = 0, tmp = num;
        while(tmp > 0) {  // 计算num的二进制位数
            ++bit_len;
            tmp >>= 1;
        }
        for(int bl = 2; bl <= bit_len; ++bl) {
            vector<int> res_tmp;
            for(auto v : res) 
                res_tmp.push_back(v + 1);
            res.insert(res.end(), res_tmp.cbegin(), res_tmp.cend());
        }
        return vector<int>(res.cbegin(), res.cbegin() + num + 1);
    }
};


// Solution2: O(N)
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res(num + 1, 0);
        int offset = 1;
        for(int i = 1; i <= num; ++i) {
            if(offset * 2 == i)
                offset *= 2;
            res[i] = res[i - offset] + 1;
        }
        return res;
    }
};


