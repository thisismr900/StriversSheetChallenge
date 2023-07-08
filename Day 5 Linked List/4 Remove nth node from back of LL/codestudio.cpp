/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/

Node* removeKthNode(Node* head, int k)
{
    if(head==NULL || k==0) return head;
    
    Node * temp=head;
    int cnt=0;
    while(temp!=NULL)
    {
        temp=temp->next;
        cnt++;

    }
    if(k==cnt)
    {
        //remove first node
        return head->next; 
    }

    //k<=cnt
    temp=head;

    while(cnt>k+1)
    {
        temp=temp->next;
        cnt--;
    }
    //delete temp->next manually
    // Node*x=temp->next;
    temp->next=temp->next->next;
    // free(x);

    return head;
}
