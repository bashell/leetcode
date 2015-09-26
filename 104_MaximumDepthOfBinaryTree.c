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
    int left_child = maxDepth(root -> left);
    int right_child = maxDepth(root -> right);
    return left_child > right_child ? left_child + 1 : right_child + 1;
}
