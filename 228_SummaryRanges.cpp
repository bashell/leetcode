class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> svec;
        if(nums.size() == 0)
            return svec;
        int i, j;
        for(i = 0; i < nums.size(); ) {
            string s = to_string(nums[i]);
            int count = 0;    
            // count == 0时, s形如: "1"
            // count > 0时, s形如: "1 -> 3"
            for(j = i + 1; j < nums.size(); ) {
                if(j - i == nums[j] - nums[i])  
                    ++count, ++j;
                else    
                    break;
            }
            --j;    // 回退一步
            if(count)    // 若能构成"a->b"的形式, 则在s后添加"->b"
                s += "->" + to_string(nums[j]);
            svec.push_back(s);
            i = j + 1;
        }
        return svec;
    }
};
