
class Solution {
public:
    // pair<bool, <max,min>> 
    pair<bool, pair<long long int  ,long long int>> isBst(TreeNode* root){
        if(root == NULL){
            // return {true, {INT_MIN, INT_MAX}};
            // Note: using INT_MIN and INT_MAX was giving error because tree node's value can itself be INT_MIN or INT_MAX
            return {true, {-1000000000000, 1000000000000}};
        }
        auto lst = isBst(root->left);
        auto rst = isBst(root->right);
        if(lst.first && rst.first && root->val > lst.second.first && root->val < rst.second.second){
            return {true, {max((long long)root->val, rst.second.first), min((long long)root->val, lst.second.second)}};
        }else{
            return {false, {max({(long long)root->val, lst.second.first, rst.second.first}) , min({(long long)root->val, lst.second.second, rst.second.second}) } };
        }
    }

    bool isValidBST(TreeNode* root) {
        pair<bool,pair<long long int ,long long int>> checkBst = isBst(root);
        return checkBst.first;
    }
};

TC = O(n) , every node is being traversed once 
