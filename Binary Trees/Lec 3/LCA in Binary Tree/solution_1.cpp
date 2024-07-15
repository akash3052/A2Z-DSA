
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL){
            return NULL;
        }
        if(root->val == p->val || root->val == q->val){
            return root;
        }
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        // Note : If left and right both are not null, then we have found the lca.
        if(left && right){
            return root;
        }else if(!left && !right){
            return NULL;
        }else{
            // Note : If one of the left or right is null, then we will pass the not null values to upper layer.
            return (left) ? left : right;
        }
    }
};
