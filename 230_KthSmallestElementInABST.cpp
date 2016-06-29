/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// Solution1: recursive
class Solution {
public:
    int countNodes(TreeNode *root) {
        if(root == NULL) return 0;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        int left_num = countNodes(root->left);  // 左子树结点个数
        if(left_num + 1 == k)  // root为所求
            return root->val;
        else if(left_num + 1 > k)  // 位于左子树
            return kthSmallest(root->left, k);
        else  // 位于右子树
            return kthSmallest(root->right, k - 1 - left_num);
    }
};

// Solution2: iterative
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> stk;
        while(root) {
            stk.push(root);
            root = root->left;
        }
        while(k > 0) {
            TreeNode *tmp = stk.top();
            stk.pop();
            if(--k == 0) return tmp->val;  // find
            tmp = tmp->right;
            while(tmp) {
                stk.push(tmp);
                tmp = tmp->left;
            }
        }
        return -1;
    }
};
