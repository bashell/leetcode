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
    bool isSymmetric(TreeNode* root) {
        if(root == NULL)
            return true;
        invertTree(root -> right);  // 反转右子树
        if(isSameTree(root -> left, root -> right)) {   // 判断反转右子树后，左右子树是否相同
            invertTree(root -> right);
            return true;
        } else {
            invertTree(root -> right);
            return false;
        }
    }
    
    TreeNode* invertTree(TreeNode *root) {
        if(root == NULL)
            return NULL;
        TreeNode *temp = root -> left;
        root -> left = root -> right;
        root -> right = temp;
        invertTree(root -> left);
        invertTree(root -> right);
        return root;
    }
    
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if(p == NULL && q == NULL)
            return true;
        else if(p == NULL && q != NULL || p != NULL && q == NULL)
            return false;
        else if(p -> val !=  q -> val)
            return false;
        else if(isSameTree(p -> left, q -> left) && isSameTree(p -> right, q -> right))
            return true;
        return false;
    }
};
