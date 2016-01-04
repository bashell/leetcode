// Solution1
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        if(nums.size() < 4) return result;
        sort(nums.begin(), nums.end());
        int sz = nums.size();
        for(int i = 0; i < sz; ++i) {
            if(i > 0 && nums[i] == nums[i - 1]) continue;  // ignore same ones
            for(int j = i + 1; j < sz; ++j) {
                if(j > i + 1 && nums[j] == nums[j - 1]) continue;  // ignore same ones
                int tar = target - nums[i] - nums[j];
                for(int p = j + 1, q = sz - 1; p < q; ) {
                    if(nums[p] + nums[q] == tar) {
                        vector<int> tmp{nums[i], nums[j], nums[p], nums[q]};
                        result.push_back(tmp);
                        while(p < q && nums[p] == nums[p + 1]) ++p;  // ignore same ones
                        while(p < q && nums[q] == nums[q - 1]) --q;  // ignore same ones
                        ++p, --q;
                    } else if(nums[p] + nums[q] < tar) {
                        ++p;
                    } else {
                        --q;
                    }
                }
            }
        }
        return result;
    }
};

// Solution2
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        if(nums.size() < 4) return result;
        sort(nums.begin(), nums.end());
        int sz = nums.size();
        for(int i = 0; i < sz - 3; ++i) {
            if(i > 0 && nums[i] == nums[i-1]) continue;
            if(nums[i] + nums[i+1] + nums[i+2] + nums[i+3] > target) break;
            if(nums[i] + nums[sz-3] + nums[sz-2] + nums[sz-1] < target) continue;
            for(int j = i + 1; j < sz - 2; ++j) {
                if(j > i + 1 && nums[j] == nums[j-1]) continue;
                if(nums[i] + nums[j] + nums[j+1] + nums[j+2] > target) break;
                if(nums[i] + nums[j] + nums[sz-2] + nums[sz-1] < target) continue;
                int tar = target - nums[i] - nums[j];
                for(int p = j + 1, q = sz - 1; p < q; ) {
                    if(nums[p] + nums[q] == tar) {
                        vector<int> tmp{nums[i], nums[j], nums[p], nums[q]};
                        result.push_back(tmp);
                        while(p < q && nums[p] == nums[p+1]) ++p;
                        while(p < q && nums[q] == nums[q-1]) --q;
                        ++p, --q;
                    } else if(nums[p] + nums[q] < tar) {
                        ++p;
                    } else {
                        --q;
                    }
                }
            }
        }
        return result;
    }
};
