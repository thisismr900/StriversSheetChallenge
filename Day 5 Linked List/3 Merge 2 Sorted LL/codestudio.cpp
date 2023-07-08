#include <bits/stdc++.h>

/************************************************************

    Following is the linked list node structure.
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/

Node<int>* sortTwoLists(Node<int>* head1, Node<int>* head2)
{
    Node<int>*curr;
    Node<int>*prev;
    Node<int>*temp;
    Node<int>*ans;
    if(head1==NULL)return head2;//1st list empty
    if(head2==NULL)return head1;//2nd list empty
    
    if(head1->data < head2->data){
        ans=head1;
        temp=head2;
    }
    else{
        ans=head2;
         temp=head1;
    }

    prev=ans;
    curr=ans->next;

    while(curr!=NULL && temp!=NULL)
    {
        if(prev->data <= temp->data && temp->data <= curr->data)
        {
            Node<int>*temp2=temp->next;
            prev->next=temp;
            temp->next=curr;
            temp=temp2;
            prev=prev->next;
        }
        else{
            prev=curr;
            curr=curr->next;
        }
    }

    if(curr==NULL && temp !=NULL) //EDGE CASE
        prev->next=temp;
    
    return ans;
}
