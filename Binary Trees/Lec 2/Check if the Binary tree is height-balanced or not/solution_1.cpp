
class Solution {

public:
    // Function to check if a binary tree is balanced
    bool isBalanced(TreeNode* root) {
        return dfsHeight(root) != -1;
    }

    // Recursive function to calculate
    // the height of the tree
    int dfsHeight(TreeNode* root) {
        // Base case: if the current node is NULL,
        // return 0 (height of an empty tree)
        if (root == NULL) return 0;

        // Recursively calculate the
        // height of the left subtree
        int leftHeight = dfsHeight(root->left);

        // If the left subtree is unbalanced,
        // propagate the unbalance status
        if (leftHeight == -1) 
            return -1;

        // Recursively calculate the
        // height of the right subtree
        int rightHeight = dfsHeight(root->right);

        // If the right subtree is unbalanced,
        // propagate the unbalance status
        if (rightHeight == -1) 
            return -1;

        // Check if the difference in height between
        // left and right subtrees is greater than 1
        // If it's greater, the tree is unbalanced,
        // return -1 to propagate the unbalance status
        if (abs(leftHeight - rightHeight) > 1)  
            return -1;

        // Return the maximum height of left and
        // right subtrees, adding 1 for the current node
        return max(leftHeight, rightHeight) + 1;
    }
};
