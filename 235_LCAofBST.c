/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 
 // 本题要利用BST的性质：left < root < right
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if(root == NULL)
        return NULL;
        
    // p、q位于根root的两侧时，根root为它们的LCA. 等号成立说明p、q至少有一个为root        
    if((p -> val - root -> val) * (q -> val - root -> val) <= 0)
        return root;
        
    // p、q位于root的右侧时
    else if(p -> val > root -> val && q -> val > root -> val)
        return lowestCommonAncestor(root -> right, p, q);
    
    // p、q位于root的左侧时
    else if(p -> val < root -> val && q -> val < root -> val)
        return lowestCommonAncestor(root -> left, p, q);
}
