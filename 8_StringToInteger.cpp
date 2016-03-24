class Solution {
public:
    int myAtoi(string str) {
        // empty
        if(str.size() == 0) 
            return 0;
            
        // skip consecutive spaces
        const char *ch = str.c_str();
        while(*ch == ' ') ++ch;
        
        // handle signs
        int sign = 1;
        if(*ch == '+') {
            ++ch;
        } else if(*ch == '-') {
            sign = -1;
            ++ch;
        }
        if(!isdigit(*ch))
            return 0;
            
        // cal
        int res = 0;
        while(ch && isdigit(*ch)) {
            int digit = *ch - '0';
            if(INT_MAX/10 < res || INT_MAX/10 == res && INT_MAX%10 < digit)
                return sign == 1 ? INT_MAX : INT_MIN;
            res = 10 * res + digit;
            ++ch;
        }
        return res * sign;
    }
};
