
class Solution {
public:

    void solve(TreeNode* root, int &k, int &res, int count){
        if(root == NULL){
            return;
        }
        solve(root->left, k, res, count);
        if(++count == k){
            res = root->val;
            return;
        }
        solve(root->right, k, res, count);
    }

    int kthSmallest(TreeNode* root, int k) {
        int res = INT_MAX;
        solve(root, k, res, 0);
        return res;
    }
};


TC = O(n), where n = no of nodes in the tree


