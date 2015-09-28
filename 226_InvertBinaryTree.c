/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* invertTree(struct TreeNode* root) {
    if(root == NULL)
        return NULL;    
    struct TreeNode *temp;
    // 交换左右子树
    temp = root -> left;
    root -> left = root -> right;
    root -> right = temp;
    // 递归
    invertTree(root -> left);
    invertTree(root -> right);
    return root;
}
