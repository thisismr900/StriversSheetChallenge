#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/
LinkedListNode<int> *reverse(LinkedListNode<int> *head)
{
    if(head==NULL || head->next==NULL)return head;
    LinkedListNode<int> *prev=NULL,*curr=head,*nex;
    while(curr!=NULL)
    {
        nex=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nex;
    }
    return prev;
    
}



bool isPalindrome(LinkedListNode<int> *head) {
    bool result=true;
    if(head==NULL|| head->next==NULL)return true;
    
    //step1 : find middle
    LinkedListNode<int> *slow=head,*fast=head,*middle;
    
    while(fast->next!=NULL && fast->next->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    middle=slow;
    
    //step 2 : reverse the LL after middle
    middle->next=reverse(middle->next);
    
    //step 3: compare both halves
    LinkedListNode<int> *t1=head,*t2=middle->next;
    while(t2!=NULL)
    {
        if(t1->data != t2->data)
        {
            result=false;
            break;
        }
        t1=t1->next;
        t2=t2->next;
    }
    //step 4: jo tumne linked list ko chera hai , sahi kar do pehle jaise
    middle->next=reverse(middle->next);
    return result;

}