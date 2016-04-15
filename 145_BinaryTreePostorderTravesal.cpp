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

// Iterative

/*
    root - right - left
          |
          | reverse
          |
    left - right -root
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if(NULL == root)
            return res;
        std::stack<TreeNode *> stk;
        stk.push(root);
        while(!stk.empty()) {
            TreeNode *tmp = stk.top();
            stk.pop();
            res.push_back(tmp->val);
            if(tmp->left) 
                stk.push(tmp->left);
            if(tmp->right)
                stk.push(tmp->right);
        }
        return vector<int>(res.crbegin(), res.crend());
    }
};
