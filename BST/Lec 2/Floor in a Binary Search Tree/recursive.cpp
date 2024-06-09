class Solution{

public:
    int floor(Node* root, int x) {
        if(root == NULL){
            return -1;
        }
        if(root->data == x){
            return root->data;
        }
        if(root->data < x){
            int tempfloor = floor(root->right, x);
            return (tempfloor <= x && tempfloor != -1) ? tempfloor : root->data;
        }else{
            return floor(root->left, x);
        }
    }
};


TC = O(logn) 
