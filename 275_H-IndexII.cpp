class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int left = 0, right = n-1, mid;
        while(left <= right) {
            mid = left + (right - left) / 2;
            if(citations[mid] == n-mid)  // find
                return citations[mid];
            else if(citations[mid] > n-mid)  // go left
                right = mid - 1;
            else  // go right
                left = mid + 1;
        }
        return n - left;
    }
};
