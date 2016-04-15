/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// Recirsive
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

// Iterative
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if(NULL == root) return vector<int>();
        std::stack<TreeNode*> stk;
        stk.push(root);
        vector<int> res;
        while(!stk.empty()) {
            TreeNode *tmp = stk.top();
            stk.pop();
            res.push_back(tmp->val);
            if(tmp->right) {
                stk.push(tmp->right);
            }
            if(tmp->left) {
                stk.push(tmp->left);
            }
        }
        return res;
    }
};
