class Solution {
public:
    bool isPalindrome(string s) {
        if(s.size() == 0) return true;
        vector<char> cvec;
        for(auto c : s) {
            if(isupper(c)) {
                c += 32;
                cvec.push_back(c);
            } else if(islower(c)) {
                cvec.push_back(c);
            } else if(c >= '0' && c <= '9') {
                cvec.push_back(c);
            }
        }
        int n = cvec.size();
        for(int i = 0, j = n-1; i <= j; ++i, --j) 
            if(cvec[i] != cvec[j])
                return false;
        return true;
    }
};
