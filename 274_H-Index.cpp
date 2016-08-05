class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        if(n == 0) return 0;
        std::sort(citations.begin(), citations.end());
        int res = n;
        for(int i = 0; i < n; ++i) {
            if(citations[i] >= res)  // find
                return res;
            else
                --res;
        }
        return 0;  // all zero
    }
};
