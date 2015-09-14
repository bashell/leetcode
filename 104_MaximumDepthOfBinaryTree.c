/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxDepth(struct TreeNode* root) {
    if(root == NULL)
        return 0;
    int left_branch = maxDepth(root -> left);
    int right_branch = maxDepth(root -> right);
    return left_branch > right_branch ? left_branch + 1 : right_branch + 1;
}