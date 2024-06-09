int findCeil(Node* root, int input) {
    if (root == NULL) return -1;
    int ceil = -1;
    while(root){
        if(root->data == input){
            ceil = root->data;
            return ceil;
        }else if (root->data < input){
            root = root->right;
        }else{
            // root->data > input
            // since, we are going left, ceil value will be minm than the previous ceil value
            // Hence, we are not checking from previous value.
            ceil = root->data;
            root = root->left;
        }
    }
    return ceil;

    // Your code here
}


TC = O(logn) [O(height of BST)]
