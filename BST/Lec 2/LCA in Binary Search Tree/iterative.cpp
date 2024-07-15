
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* curr = root;
        while(true){
            int currVal = curr->val;
            if(p->val < currVal && q->val < currVal){
                curr = curr->left;
            }else if (p->val > currVal && q->val > currVal){
                curr = curr->right;
            }else{
                break;
            }
        }
        return curr;
    }
};
