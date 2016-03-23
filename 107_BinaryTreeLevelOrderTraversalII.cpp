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
    void levelOrderHelper(TreeNode* root, int level, vector<vector<int>> &res) {
        if(root == NULL) return;
        if(res.size() == level)
            res.push_back(vector<int>{});
        res[level].push_back(root->val);
        levelOrderHelper(root->left, level+1, res);
        levelOrderHelper(root->right, level+1, res);
    }
    
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if(root == NULL) return res;
        levelOrderHelper(root, 0, res);
        return vector<vector<int>> {res.rbegin(), res.rend()};
    }
};
