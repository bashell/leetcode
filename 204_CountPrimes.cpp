class Solution {
public:
    int countPrimes(int n) {
        vector<int> flag(n, 1);
        for(int i = 2; i * i < n; ++i) {
            if(flag[i] == 0) continue;
            for(int j = i * i; j < n; j += i)
                flag[j] = 0;
        }
        int count = 0;
        for(int i = 2; i < n; ++i)
            if(flag[i] == 1)
                ++count;
        return count;
    }
};
