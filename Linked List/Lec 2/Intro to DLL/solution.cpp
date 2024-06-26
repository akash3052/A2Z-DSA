class Solution {
  public:
    Node* constructDLL(vector<int>& arr) {
        Node* head = new Node(arr[0]);
        Node* curr = head;
        for(int i = 1; i < arr.size(); i++){
            curr->next = new Node(arr[i]);
            curr->next->prev = curr;
            curr = curr->next;
        }
        return head;
    }
};

