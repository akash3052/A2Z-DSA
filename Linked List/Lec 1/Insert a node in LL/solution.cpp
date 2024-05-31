class Solution{
  public:
    //Function to insert a node at the beginning of the linked list.
    Node *insertAtBegining(Node *head, int x) {
       // Your code here
       Node* curr = new Node(x);
       curr->next = head;
       head = curr;
       return head;
    }
    
    
    //Function to insert a node at the end of the linked list.
    Node *insertAtEnd(Node *head, int x)  {
      // Note: below conditon is important. Test cases were failing without this.
       if(!head){
           return new Node(x);
       }
       Node* curr = head;
       while(curr->next){
           curr = curr->next;
       }
       curr->next = new Node(x);
       return head;
    }
};
