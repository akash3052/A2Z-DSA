
class Solution {
public:

    bool isBST(TreeNode* root, long long minValue, long long maxValue){
        if(root == NULL){
            return true;
        }
        if(root->val >= maxValue || root->val <= minValue){
            return false;
        }
        return isBST(root->left, minValue, root->val) && isBST(root->right, root->val, maxValue);
    }

    bool isValidBST(TreeNode* root) {
        // Note : Here also INT_MIN and INT_MAX was not working because the tree value can also be this.
        // return isBST(root, INT_MIN, INT_MAX);
        return isBST(root, -1000000000000, 1000000000000);
    }
};

