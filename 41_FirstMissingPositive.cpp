class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if(nums.size() == 0)
            return 1;
        set<int> iset;
        for(vector<int>::iterator vec_it = nums.begin(); vec_it != nums.end(); ++vec_it)
            if(*vec_it > 0)
                iset.insert(*vec_it);
        if(iset.size() == 0)    // vector中没有正数
            return 1;
        
        int set_min = *(iset.begin());    // 容器set中的最小元素
        if(set_min >= 2)
            return 1;

        int temp = set_min;
        // 从最小元素逐次递增比较, 找出没有出现在set中的数
        for(set<int>::iterator set_it = iset.begin(); set_it != iset.end(); ++set_it, ++temp)
            if(temp != *set_it)
                return temp;
        return temp;    // set中元素连续
    }
};
