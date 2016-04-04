class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> cmap{{'(', ')'}, {'[', ']'}, {'{', '}'}};
        unordered_set<char> left_case{'(', '[', '{'};
        unordered_set<char> right_case{')', ']', '}'};
        stack<char> stk;
        for(int i = 0; i < s.size(); ++i) {
            if(left_case.find(s[i]) != left_case.end()) {
                stk.push(s[i]);
            } 
            if(right_case.find(s[i]) != right_case.end()) {
                if(stk.empty()) {
                    return false;
                } else {
                    char tmp = stk.top();
                    stk.pop();
                    if(cmap[tmp] != s[i])
                        return false;
                }
            } 
        }
        return stk.empty() ? true : false;
    }
};
