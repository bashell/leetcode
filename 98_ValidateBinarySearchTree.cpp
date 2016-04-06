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
    void getNodeVal(TreeNode *root, vector<int> &ivec) {
        if(!root)
            return ;
        getNodeVal(root->left, ivec);
        ivec.push_back(root->val);
        getNodeVal(root->right, ivec);
    }
    
    bool isValidBST(TreeNode* root) {
        if(!root)
            return true;
        int rv = root->val;
        if(root->left && root->left->val >= rv || root->right && root->right->val <= rv)
            return false;
        if(!isValidBST(root->left) || !isValidBST(root->right))
            return false;
        vector<int> left_node, right_node;
        getNodeVal(root->left, left_node);
        getNodeVal(root->right, right_node);
        for(const auto n : left_node)
            if(n >= rv)
                return false;
        for(const auto n : right_node)
            if(n <= rv)
                return false;
        return true;
    }
};

// Solution2
class Solution {
public:
    bool isValidHelper(TreeNode *root, long min, long max) {
        if(!root) return true;
        return min < root->val && root->val < max && isValidHelper(root->left, min, root->val) && isValidHelper(root->right, root->val, max);
    }
    
    bool isValidBST(TreeNode* root) {
        return isValidHelper(root, LONG_MIN, LONG_MAX);
    }
};

