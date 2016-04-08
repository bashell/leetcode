class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_pri = INT_MAX, max_pro = 0;
        for(auto p : prices) {
            min_pri = std::min(min_pri, p);
            max_pro = std::max(max_pro, p - min_pri);
        }
        return max_pro;
    }
};
