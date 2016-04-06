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
    void preorderHelper(TreeNode *root, vector<int> &ivec) {
        if(!root)
            return ;
        ivec.push_back(root->val);
        preorderHelper(root->left, ivec);
        preorderHelper(root->right, ivec);
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        preorderHelper(root, res);
        return res;
    }
};
