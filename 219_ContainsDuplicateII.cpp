class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> elements;
        int cnt = nums.size();
        for(int i = 0; i != cnt; ++i)
            ++elements[nums[i]];
        for(const auto &e : elements) {
            if(e.second >= 2) {  // contains duplicate: e.second
                vector<int> ivec;
                for(int j = 0; j != cnt; ++j) {
                    if(nums[j] == e.first)
                        ivec.push_back(j);  // ivec already in ascending order
                }
                for(int j = 0; j != ivec.size() - 1; ++j) {
                    if(ivec[j] + k >= ivec[j+1])  // the difference between ivec[j] and ivec[j+i] is at most k
                        return true;
                }
            }
        }
        return false;        
    }
};
