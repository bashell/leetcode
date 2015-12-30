class Solution{
    public:
        vector<int> twoSum(vector<int> &nums, int target) {
            unordered_map<int, int> imap;
            vector<int> result;
            for(int i = 0; i < nums.size(); i++)
                imap[nums[i]] = i;
            for(int i = 0; i < nums.size(); i++) {
                int gap = target - nums[i];
                if(imap.find(gap) != imap.end() && imap[gap] > i) {
                    result.push_back(i + 1);  // index is not zero-based
                    result.push_back(imap[gap] + 1);
                    break;
                }
            }
            return result;
        }
};
