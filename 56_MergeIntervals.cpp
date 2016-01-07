/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> result;
        int sz = intervals.size();
        if(sz == 0) return result;
        // 将输入数据按区间起始点大小排序
        std::sort(intervals.begin(), intervals.end(), 
                  [](const Interval &i1, const Interval &i2) { return i1.start < i2.start; });
        int left, right;
        int flag = 1;  // 1: 完成了push_back  0: 更新了right, 有待于push_back
        for(int i = 0; i < sz - 1; ++i) {
            if(flag) {
                left = intervals[i].start;
                right = intervals[i].end;
            }
            if(intervals[i+1].start > right) {
                result.push_back(Interval{left, right});
                flag = 1;
            } else {
                right = std::max(right, intervals[i+1].end);  // 更新right
                flag = 0;
            }
        }
        if(flag)
            result.push_back(intervals[sz-1]);  // intervals[sz-1].start > right
        else
            result.push_back(Interval{left, right});  // intervals[sz-1].start <= right 且right已更新
        return result;
    }
};
