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
    void postorderHelper(TreeNode *root, vector<int> &ivec) {
        if(!root)
            return ;
        postorderHelper(root->left, ivec);
        postorderHelper(root->right, ivec);
        ivec.push_back(root->val);
    }
    
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        postorderHelper(root, res);
        return res;
    }
};
