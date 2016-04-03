/*
DP策略，tabulation(Bottom Up)

利用对称性：（n扩大1位时，原数据前加0，对称数据前加1）
 n = 1
 0
 1
 
 n = 2
 0 0
 0 1
 1 1
 1 0
 
 n = 3
 0 0 0
 0 0 1
 0 1 1
 0 1 0
 1 1 0
 1 1 1
 1 0 1
 1 0 0
 
*/

class Solution {
public:
    vector<int> grayCode(int n) {
        if(n == 0) return vector<int>{0};
        if(n == 1) return vector<int>{0, 1};
        vector<int> res{0, 1};
        for(int i = 1; i < n; ++i) {
            vector<int> tmp(res.cbegin(), res.cend());
            for(auto &t : tmp)
                t += (1 << i);
            res.insert(res.end(), tmp.crbegin(), tmp.crend());
        }
        return res;
    }
};
