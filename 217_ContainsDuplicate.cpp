// Solution1
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::unordered_map<int, int> elements;
        int cnt = nums.size();
        for(int i = 0; i != cnt; ++i)
            ++elements[nums[i]];
        for(const auto &e : elements)
            if(e.second >= 2)
                return true;
        return false;
    }
};

// Solution2
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> iset(nums.cbegin(), nums.cend());
        return nums.size() != iset.size() ? true : false;
    }
};
