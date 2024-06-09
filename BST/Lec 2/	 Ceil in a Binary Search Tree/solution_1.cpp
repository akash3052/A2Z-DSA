int findCeil(Node* root, int input) {
    if (root == NULL) return -1;
    if (input == root->data){
        return input;
    }
    if(root->data < input){
        return findCeil(root->right, input);
    }else{ 
        // root->data > input
        // If the key is grater than X , 
        // then the node can be a possible solution 
        // but to get immediate greater value we have to call the function with left subtree
        int cceil = findCeil(root->left, input);
        return (cceil >= input) ? cceil : root->data;
    }

    // Your code here
}

