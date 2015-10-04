class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int, int> elements;
        for(int i = 0; i != nums.size(); ++i)
            ++elements[nums[i]];
        for(map<int, int>::iterator iter = elements.begin(); iter != elements.end(); ++iter)
            if(iter -> second >= 2)
                return true;
        return false;
    }
};
