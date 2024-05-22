class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root){
            return new TreeNode(val);
        }
        TreeNode* temp = root;
        while(root){
            if(val < root->val){
                if(root->left != NULL){
                    root = root->left;
                }else{
                    root->left = new TreeNode(val);
                    break;
                }
            }else{
                if(root->right != NULL){
                    root = root->right;
                }else{
                    root->right = new TreeNode(val);
                    break;
                }
            }
        }
        return temp;
    }
};

TC = O(logn)
SC = O(logn)


  
