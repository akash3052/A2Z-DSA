void addNode(Node *head, int pos, int data)
{
    int index = 0;
    Node* curr = head;
    while(index != pos){
        curr = curr->next;
        index++;
    }
    Node* newNode = new Node(data);
    newNode->next = curr->next;
    newNode->prev = curr;
    curr->next = newNode;
    if(newNode->next != NULL){
        newNode->next->prev = newNode;
    }
}

