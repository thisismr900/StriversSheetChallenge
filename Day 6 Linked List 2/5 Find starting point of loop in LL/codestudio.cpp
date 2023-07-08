/****************************************************************

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


*****************************************************************/
#include<bits/stdc++.h>
Node *firstNode(Node *head)
{
    /*
//better:hashing
    if(head==NULL|| head->next==NULL) return NULL;
    unordered_set<Node*>nodeSet;
    Node* temp=head;
    while(temp!=NULL)
    {
        if(nodeSet.find(temp)!=nodeSet.end())
        { //already visited this node
            return temp;
        }
        nodeSet.insert(temp);
        temp=temp->next;
    }
    return NULL;

*/





// optimal: 2pointer

    if(head==NULL|| head->next==NULL) return NULL;
    Node* slow=head;
    Node* fast=head->next;
    while(fast!=NULL && fast->next!=NULL)
    {
        if(slow==fast)
        {
            break;
        }
        slow=slow->next;
        fast=fast->next->next;
    }
    if(slow==fast)
    {
                    // cycle exists
            Node* t1=fast->next;
            Node* t2=head;
            while(t1!=t2)
            {
                t1=t1->next;
                t2=t2->next;
            }
            Node* ans=t1;
            //find the answer node then return it
            return ans;
    }
    return NULL;

}