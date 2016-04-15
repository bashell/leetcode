/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// Recursive
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

// Iterative
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if(NULL == root)
            return vector<int>();
        std::stack<TreeNode *> stk;
        vector<int> res;
        TreeNode *pCur = root;
        while(pCur || !stk.empty()) {
            if(pCur) {
                stk.push(pCur);
                pCur = pCur->left;
            } else {
                TreeNode *tmp = stk.top();
                stk.pop();
                res.push_back(tmp->val);
                pCur = tmp->right;
            }
        }
        return res;
    }
};
