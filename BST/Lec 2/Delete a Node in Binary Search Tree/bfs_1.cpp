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
        // Here, I was making one mistake that instead of curr, I was writing root
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
            curr->right = deleteNode(curr->right, inorderSuccessor->val);
        }else{ // one child present
            if(curr != root){
                if(curr->left != NULL){
                    if(curr == parent->left){
                        parent->left = curr->left;
                    }else{
                        parent->right = curr->left;
                    }
                }else{
                    // curr->right != NULL
                    if(curr == parent->left){
                        parent->left = curr->right;
                    }else{
                        parent->right = curr->right;
                    }
                }
            }else{
                root = (curr->left) ? curr->left : curr->right;
            }
            delete curr;
        }
        return root;
    }
};

// Time Complexity: O(H) where H is the height of the tree. 
// This is due to the binary search applied while finding the node with value as key. 
// All other operations performed are in constant time. O(H) ~ O(log N) in case of a full binary search tree (optimal time).


