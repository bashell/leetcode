class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int, int> elements;
        for(int i = 0; i != nums.size(); ++i)     // 将vector中的元素拷贝到map容器中, 形成pair<const int, int>
            ++elements[nums[i]];
        for(map<int, int>::iterator iter = elements.begin();    // 遍历map, 查看是否满足条件
                iter != elements.end(); ++iter)
            if(iter -> second >= 2)
                return true;
        return false;
    }
};
