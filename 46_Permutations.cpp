// Solution1: backtracking
class Solution {
public:
    // nums: pass-by-value
    void permuteHelper(vector<int> nums, int beg, vector<vector<int>> &res) {
        if(beg == nums.size()-1) {
            res.push_back(nums);
            return ;
        }
        // nums[0...beg-1] is fixed
        for(int i = beg; i < nums.size(); ++i) {
            swap(nums[i], nums[beg]);  // swap
            permuteHelper(nums, beg+1, res);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        permuteHelper(nums, 0, res);
        return res;
    }
};

// Solution2: next_permutation()
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.size() == 0) return res;
        std::sort(nums.begin(), nums.end());
        res.push_back(nums);
        while(next_permutation(nums.begin(), nums.end()))
            res.push_back(nums);
        return res;
    }
};
