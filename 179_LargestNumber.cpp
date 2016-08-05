class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string res("");
        vector<string> svec;
        for(auto item : nums)
            svec.push_back(to_string(item));
        std::sort(svec.begin(), svec.end(), 
                  [](const string &s1, const string &s2)
                  { return s1+s2 > s2 + s1; });
        for(const auto &item : svec)
            res.append(item);
        while(res[0] == '0' && res.size() > 1)
            res.erase(0, 1);
        return res;
    }
};
