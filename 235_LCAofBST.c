/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 
 // ����Ҫ����BST�����ʣ�left < root < right
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if(root == NULL)
        return NULL;
        
    // p��qλ�ڸ�root������ʱ����rootΪ���ǵ�LCA��'= 0'ʱ˵��p��q����������һ��Ϊroot        
    if((p -> val - root -> val) * (q -> val - root -> val) <= 0)
        return root;
        
    // p��qλ��root���Ҳ�ʱ
    else if(p -> val > root -> val && q -> val > root -> val)
        return lowestCommonAncestor(root -> right, p, q);
    
    // p��qλ��root�����ʱ
    else if(p -> val < root -> val && q -> val < root -> val)
        return lowestCommonAncestor(root -> left, p, q);
    
}