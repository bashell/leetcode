class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res{0};
        for(int i = 0; i < n; ++i) {  // i控制bit位数
            int cnt = res.size();
            for(int j = cnt - 1; j >= 0; --j) {  // j用于逆序在最高位前添加1
                int tmp = res[j];
                tmp += (1<<i);
                res.push_back(tmp);
            }
        }
        return res;
    }
};

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
