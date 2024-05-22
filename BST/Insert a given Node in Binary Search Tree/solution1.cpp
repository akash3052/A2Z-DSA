class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root){
            return new TreeNode(val);
        }
        TreeNode* rootParent = NULL;
        TreeNode* currNode = root;
        bool left = false, right = false;
        while(currNode){
            rootParent = currNode;
            if(val < currNode->val){
                currNode = currNode->left;
                left = true;
                right = false;
            }else{
                currNode = currNode->right;
                right = true;
                left = false;
            }
        }
        if(left){
            rootParent->left = new TreeNode(val);
        }else{
            rootParent->right = new TreeNode(val);
        }
        return root;
    }
};

