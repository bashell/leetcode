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
    void inorderHelper(TreeNode *root, vector<int> &ivec) {
        if(!root)
            return ;
        inorderHelper(root->left, ivec);
        ivec.push_back(root->val);
        inorderHelper(root->right, ivec);
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        inorderHelper(root, res);
        return res;
    }
};
