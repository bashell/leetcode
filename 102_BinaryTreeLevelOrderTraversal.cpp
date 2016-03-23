/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// Solution1
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == NULL) return res;
        queue<TreeNode*> q;
        vector<int> tmp;
        q.push(root);
        q.push(NULL);
        while(!q.empty()) {
            TreeNode *tn = q.front();
            q.pop();
            if(tn) {
                tmp.push_back(tn->val);
                if(tn->left) q.push(tn->left);
                if(tn->right) q.push(tn->right);
            } else {
                res.push_back(tmp);
                tmp.clear();
                if(q.size() > 0)
                    q.push(NULL);
            }
        }
        return res;
    }
};

// Solution2
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
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == NULL) return res;
        levelOrderHelper(root, 0, res);
        return res;
    }
};

