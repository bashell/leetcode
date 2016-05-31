class Solution {
public:
    // left, right分别代表剩余'('和')'的个数
    void backtracking(vector<string> &res, string str, int left, int right) {
        if(left == 0 && right == 0) {
            res.push_back(str);
            return ;
        }    
        if(left > 0) 
            backtracking(res, str+'(', left-1, right);
        if(right > left) 
            backtracking(res, str+')', left, right-1);
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        backtracking(res, "", n, n);
        return res;
    }
};
