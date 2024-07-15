
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL){
            return NULL;
        }
        int currVal = root->val;
        if(p->val > currVal && q->val > currVal){
            return lowestCommonAncestor(root->right, p, q);
        }
        if(p->val < currVal && q->val < currVal){
            return lowestCommonAncestor(root->left, p, q);
        }
        // Note : If both nodes are neither on the left nor on the right, then that node is our answer.
        // 2 case can happen : i. one is at left and other is at right ii. one node is root itself.
        // In both the case, root will be the answer.
        return root;
    }
};

TC = O(height) -> O(logn)
SC = O(1)

  
