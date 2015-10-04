#include <iostream>
#include <string>
using namespace std;

class Solution{
public:
    string convertTotile(int n) {
        string str;
        for( ; n > 0; n /= 26) {
            n -= 1;
            str = (char)('A' + n % 26) + str;    // 由于字符是从右向左得到的
        }
        return str;
    }
};

int main()
{
    Solution solu;
    string str1 = solu.convertTotile(24);
    string str2 = solu.convertTotile(26);
    string str3 = solu.convertTotile(28);
    cout << str1 << '\n' << str2 << '\n' << str3 << endl;

    return 0;
}
