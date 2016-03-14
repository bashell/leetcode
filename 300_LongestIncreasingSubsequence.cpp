// T(n) = O(n^2)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len = nums.size(), max = 0;
        if(len <= 1) return len;
        vector<int> lisHelper(len, 1);
        for(int i = 1; i < len; ++i) 
            for(int j = 0; j < i; ++j) 
                if(nums[j] < nums[i] && lisHelper[j] + 1 > lisHelper[i])
                    lisHelper[i] = lisHelper[j] + 1;
        for(auto val : lisHelper) 
            if(max < val)
                max = val;
        return max;
    }
};

// T(n) = O(nlogn)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() <= 1) return nums.size();
        vector<int> res;
        for(auto i : nums) {
            auto iter = std::lower_bound(res.begin(), res.end(), i);
            if(iter == res.end())
                res.push_back(i);
            else
                *iter = i;
        }
        return res.size();
    }
};
