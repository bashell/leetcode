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
    TreeNode* buildTreeHelper(vector<int> &preorder, vector<int> &inorder, int pre_beg, int pre_end, int in_beg, int in_end) {
        if(pre_beg > pre_end) return NULL;
        int root_val = preorder[pre_beg];
        TreeNode *root = new TreeNode(root_val);
        int root_index = in_beg, left_part = 0;  // root_index: 中序下的根坐标  left_part: 左子树大小
        while(root_index <= in_end && inorder[root_index] != root_val) {
            ++root_index;
            ++left_part;
        }
        root->left = buildTreeHelper(preorder, inorder, pre_beg + 1, pre_beg + left_part, in_beg, root_index - 1);
        root->right = buildTreeHelper(preorder, inorder, pre_beg + left_part + 1, pre_end, root_index + 1, in_end);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() == 0) return NULL;
        return buildTreeHelper(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);
    }
};
