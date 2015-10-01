// Solution1
class Solution {
public:
    void sortColors(vector<int>& nums) {
        map<int, int> imap;
        for(int i = 0; i < nums.size(); ++i)    // imap[k]: k的个数, k = 0, 1, 2
            ++imap[nums[i]];
        for(int i = 0; i < nums.size(); ++i) {
            if(i >= 0 && i < imap[0])
                nums[i] = 0;
            else if(i >= imap[0] && i < imap[0] + imap[1])
                nums[i] = 1;
            else
                nums[i] = 2;
        }
    }
};

// Solution2
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int r = 0, w = 0, b = 0;    // r, w, b分别标记每种颜色的末尾位置
        for(int num : nums) {
            if(num == 0) {
                nums[b++] = 2;
                nums[w++] = 1;
                nums[r++] = 0;
            } else if(num == 1) {
                nums[b++] = 2;
                nums[w++] = 1;
            } else {
                b++;
            }
        }
    }
};
