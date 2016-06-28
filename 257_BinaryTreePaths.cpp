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
    void helper(vector<string> &res, string str, TreeNode *root) {
        if(!root) return;
        if(root->left == NULL && root->right == NULL)
            res.push_back(str);
        if(root->left)
            helper(res, str + "->" + to_string(root->left->val), root->left);
        if(root->right)
            helper(res, str + "->" + to_string(root->right->val), root->right);
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if(!root) return res;
        string tmp = to_string(root->val);
        helper(res, tmp, root);
        return res;
    }
};
