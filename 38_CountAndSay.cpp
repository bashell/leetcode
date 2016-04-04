class Solution {
public:
    string countAndSay(int n) {
        string res("1");
        if(n == 1) 
            return res;
        for(int k = 2; k <= n; ++k) {
            string res_tmp("");
            for(int i = 0; i < res.size();) {
                char tmp = res[i++];
                int cnt = 1;
                while(res[i] == tmp)  // count
                    ++i, ++cnt;
                res_tmp += to_string(cnt) + tmp;  // say
            }
            res = res_tmp;
        }
        return res;
    }
};
