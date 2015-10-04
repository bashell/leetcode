#include <iostream>
#include <string>
using namespace std;

class Solution{
public:
    int titleToNumber(string s) {
        int num = 0;
        for(string::size_type ix = 0; ix < s.size(); ++ix) {
            num *= 26;    // 26进制:每左移一位,都乘以26
            num += s[ix] - 'A' + 1;
        }
        return num;
    }
};

int main()
{
    Solution solu;
    int result1 = solu.titleToNumber("B");
    int result2 = solu.titleToNumber("AB");
    cout << result1 << '\n' << result2 << endl;

    return 0;
}
