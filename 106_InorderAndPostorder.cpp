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
    TreeNode* buildTreeHelper(vector<int> &inorder, vector<int> &postorder, int in_beg, int in_end, int post_beg, int post_end) {
        if(post_beg > post_end) return NULL;
        int root_val = postorder[post_end];
        TreeNode *root = new TreeNode(root_val);
        int root_index = in_end, right_part = 0;  // root_index: 中序下的根坐标  right_part: 右子树大小
        while(root_index >= 0 && inorder[root_index] != root_val) {
            --root_index;
            ++right_part;
        }
        root->left = buildTreeHelper(inorder, postorder, in_beg, root_index - 1, post_beg, post_end - 1 - right_part);
        root->right = buildTreeHelper(inorder, postorder, root_index + 1, in_end, post_end - right_part, post_end - 1);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(postorder.size() == 0) return NULL;
        return buildTreeHelper(inorder, postorder, 0, inorder.size()-1, 0, postorder.size()-1);
    }
};
