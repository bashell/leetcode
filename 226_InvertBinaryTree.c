/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* invertTree(struct TreeNode* root) {
    struct TreeNode *temp;
    if(root == NULL)
        return NULL;
        
    // 交换左右子树
    temp = root -> left;
    root -> left = root -> right;
    root -> right = temp;
    
    // 递归
    invertTree(root -> left);
    invertTree(root -> right);
    
    return root;
}
