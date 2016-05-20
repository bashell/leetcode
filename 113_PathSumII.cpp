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
    void pathSumHelper(TreeNode *root, int sum, vector<vector<int>> &res, vector<int> &path) {
        if(root == NULL) return;
        path.push_back(root->val);
        if(root->left == NULL && root->right == NULL && root->val == sum) {  // find one path
            res.push_back(path);
        } else {
            if(root->left)
                pathSumHelper(root->left, sum - root->val, res, path);
            if(root->right)
                pathSumHelper(root->right, sum - root->val, res, path);
        }
        path.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> path;
        pathSumHelper(root, sum, res, path);
        return res;
    }
};
