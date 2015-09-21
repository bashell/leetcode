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
        
    // ½»»»×óÓÒ×ÓÊ÷
    temp = root -> left;
    root -> left = root -> right;
    root -> right = temp;
    
    // µÝ¹é
    invertTree(root -> left);
    invertTree(root -> right);
    
    return root;
}