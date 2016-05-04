// Solution1: Sorting
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        std::sort(nums.begin(), nums.end());
        return nums[nums.size()-k];
    }
};

// Solution2: PriorityQueue
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.cbegin(), nums.cend());
        for(int i = 0; i < k-1; ++i) {
            pq.pop();
        }
        return pq.top();
    }
};

// Solution3: QuickSelection
class Solution {
public:
    int partition(vector<int>& nums, int low, int high) {
        int i = low, j = high+1, pivot = nums[low];
        while(1) {
            while(nums[++i] < pivot)
                if(i == high)
                    break;
            while(nums[--j] > pivot)
                if(j == low)
                    break;
            if(i >= j)
                break;
            swap(nums[i], nums[j]);
        }
        swap(nums[low], nums[j]);
        return j;
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        int sz = nums.size(), low = 0, high = nums.size()-1;
        k = sz - k;  // find the (sz-k)th smallest element
        while(low < high) {
            int p = partition(nums, low, high);
            if(p < k)
                low = p+1;
            else if(p > k)
                high = p-1;
            else
                break;
        }
        return nums[k];
    }
};


