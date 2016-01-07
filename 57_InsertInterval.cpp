/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

// Solution1
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        int n = intervals.size();
        if(n == 0)
            return vector<Interval>{newInterval};
        vector<Interval> result;
        int left = newInterval.start, right = newInterval.end;
        int index1 = n - 1, index2 = 0;
        while(index1 >= 0 && left < intervals[index1].start)  // 找到适合newInterval插入的区间起始点
            --index1;
        while(index2 < n && right > intervals[index2].end)  // 找到适合newInterval插入的区间终止点
            ++index2;

        if(index1 == -1 && index2 == n) {  // 会覆盖所有
            result.push_back(newInterval);
        } else if(index1 == -1 && index2 < n) {  // index1是最左端
            if(right >= intervals[index2].start) {
                result.push_back(Interval{left, intervals[index2].end});
                for(int i = index2 + 1; i < n; ++i)
                    result.push_back(intervals[i]);
            } else {
                result.push_back(newInterval);
                for(int i = index2; i < n; ++i)
                    result.push_back(intervals[i]);
            }
        } else if(index1 >=0 && index2 == n) {  // index2是最右端
            if(left <= intervals[index1].end) {
                result.push_back(Interval{intervals[index1].start, right});
                for(int i = index1 - 1; i >= 0; --i)
                    result.insert(result.begin(), intervals[i]);
            } else {
                result.push_back(newInterval);
                for(int i = index1; i >= 0; --i)
                    result.insert(result.begin(), intervals[i]);
            }
        } else {  // index1和index2均不会伸至两端末尾
            if(left <= intervals[index1].end && right >= intervals[index2].start) {
                result.push_back(Interval{intervals[index1].start, intervals[index2].end});
                for(int i = index1 - 1; i >= 0; --i)
                    result.insert(result.begin(), intervals[i]);
                for(int i = index2 + 1; i < n; ++i)
                    result.push_back(intervals[i]);
            } else if(left <= intervals[index1].end && right < intervals[index2].start) {
                result.push_back(Interval{intervals[index1].start, right});
                for(int i = index1 - 1; i >= 0; --i)
                    result.insert(result.begin(), intervals[i]);
                for(int i = index2; i < n; ++i)
                    result.push_back(intervals[i]);
            } else if(left > intervals[index1].end && right >= intervals[index2].start) {
                result.push_back(Interval{left, intervals[index2].end});
                for(int i = index1; i >= 0; --i)
                    result.insert(result.begin(), intervals[i]);
                for(int i = index2 + 1; i < n; ++i)
                    result.push_back(intervals[i]);
            } else {
                result.push_back(newInterval);
                for(int i = index1; i >= 0; --i)
                    result.insert(result.begin(), intervals[i]);
                for(int i = index2; i < n; ++i)
                    result.push_back(intervals[i]);
            }
        }
        
        return result;
    }
};

// Solution2
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        int left = newInterval.start, right = newInterval.end;
        vector<Interval> v1, v2;
        for(auto i : intervals) {
            if(i.end < left) {
                v1.push_back(i);
            } else if(i.start > right) {
                v2.push_back(i);
            } else {
                left = std::min(left, i.start);
                right = std::max(right, i.end);
            }
        }
        v1.push_back(Interval{left, right});
        v1.insert(v1.end(), v2.begin(), v2.end());
        return v1;
    }
};
