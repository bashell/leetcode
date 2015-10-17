// Solution1
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        if(k == 0) 
            return;
        std::reverse(nums.begin(), nums.end());             // reverse all elements
        std::reverse(nums.begin(), nums.begin() + k);       // reverse leading k elements
        std::reverse(nums.begin() + k, nums.end());         // reverse remaining elements

    }
};

// Solution2
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        if(k == 0)
            return;
        for(; k != 0; --k) {
            int temp = nums[nums.size() - 1];
            nums.pop_back();
            nums.insert(nums.begin(), temp);
        }
    }
};

// Solution3
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        if(k == 0)
            return;
        for(k = nums.size() - k; k != 0; --k) {
            int temp = nums[0];
            nums.erase(nums.begin());
            nums.push_back(temp);
        }
    }
};
