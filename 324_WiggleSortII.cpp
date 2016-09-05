/*

  1  1  1  4  5  6
  ^        ^
  |        |    
  i        j
  
 ------------------  
 
  1  1  1  4  5
  ^        ^
  |        |
  i        j

*/
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> sorted(nums);
        std::sort(sorted.begin(), sorted.end());
        int n = nums.size()-1;
        for(int i = 0, j = n/2+1; n >= 0; --n) {
            if(n & 0x1) 
                nums[n] = sorted[j++];
            else
                nums[n] = sorted[i++];
        }
    }
};
