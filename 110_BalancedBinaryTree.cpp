/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return cal_height(root) != -1;
    }
    int cal_height(TreeNode *root) {
        if(root == NULL) 
            return 0;
        int left_height = cal_height(root -> left);
        if(left_height == -1) 
            return -1;
        int right_height = cal_height(root -> right);
        if(right_height == -1)
            return -1;
        if(std::abs(left_height - right_height) > 1)
            return -1;
        return std::max(left_height, right_height) + 1;
    }
};
