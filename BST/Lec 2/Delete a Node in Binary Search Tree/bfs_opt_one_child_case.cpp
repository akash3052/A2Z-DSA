class Solution {
public:
    TreeNode* findMin(TreeNode* root){
        while(root->left){
            root = root->left;
        }
        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* curr = root;
        TreeNode* parent = NULL;
        while(curr && curr->val != key){
            parent = curr;
            if(curr->val < key){
                curr = curr->right;
            }else{
                curr = curr->left;
            }
        }
        if(curr == NULL){
            return root;
        }
        // No child present
        if(!curr->left && !curr->right){
            if(curr != root){
                if(parent->left == curr){
                    parent->left = NULL;
                }else{
                    parent->right = NULL;
                }
            }else{
                root = NULL;
            }
            delete curr;
        }
        // Two child present
        else if(curr->left && curr->right){
            TreeNode* inorderSuccessor = findMin(curr->right);
            curr->val = inorderSuccessor->val;
            // Here, I was passing root by mistake because of that it was going in infinte loop.
            curr->right = deleteNode(curr->right, inorderSuccessor->val);
        }else{ // one child present
            TreeNode* child = (curr->left) ? curr->left : curr->right;
            if(curr != root){
                if(curr == parent->left){
                    parent->left = child;
                }else{
                    parent->right = child;
                }
            }else{
                root = child;
            }
            delete curr;
        }
        return root;
    }
};

TC = O(height of tree) = O(logn)



  
