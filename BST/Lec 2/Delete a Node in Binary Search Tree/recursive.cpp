class Solution {
public:
    TreeNode* findMin(TreeNode* root){
        while(root->left){
            root = root->left;
        }
        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL){
            return NULL;
        }
        if(root->val < key){
            root->right = deleteNode(root->right, key);
            return root;
        }else if(root->val > key){
            root->left = deleteNode(root->left, key);
            return root;
        }else{// root->val == key
            if(!root->left && ! root->right){ // No child present
                delete root;
                return NULL;
            }else if (root->left and root->right){ // Two child present
                TreeNode* insucc = findMin(root->right);
                root->val = insucc->val;
                root->right = deleteNode(root->right, insucc->val);
                return root;
            }else{ // one child present
                TreeNode* child = (root->left) ? root->left : root->right;
                delete root;
                return child;
            }  
        }
    }
};


// Balanced BST (e.g., AVL Tree, Red-Black Tree): 
// For a balanced BST, the height h is O(log N), where N is the number of nodes. 
// Therefore, the time complexity in this case is O(log N). 

// Unbalanced BST: 
// For an unbalanced BST (e.g., a degenerate tree where all nodes are to one side), 
// the height h can be as large as O(N) in the worst case. Therefore, the time complexity in this case is O(N).


