#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution{
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> elements;
        for(vector<int>::iterator it = nums.begin();
                it != nums.end(); ++it)    // 统计每个元素出现的次数
            ++elements[*it];
        for(map<int, int>::iterator iter = elements.begin();
                iter != elements.end(); ++iter)    // 遍历关联容器
            if(iter -> second > nums.size() / 2)
                return iter -> first;
    }
};

int main()
{
    Solution solu;
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    cout << "The majority element is: " << solu.majorityElement(nums) << endl;
    return 0;
}
