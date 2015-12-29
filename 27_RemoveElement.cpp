class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        multiset<int> iset(nums.cbegin(), nums.cend());
        iset.erase(val);
        vector<int> tmp(iset.cbegin(), iset.cend());
        nums = tmp;
        return tmp.size();
    }
};
