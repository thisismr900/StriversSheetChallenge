#include <bits/stdc++.h>

/*************************************************************

    Following is the LinkedListNode class structure

    template <typename T>   
    class LinkedListNode
    {
        public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode<T> *random;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*************************************************************/
void copyList(LinkedListNode<int> *head)
{
    LinkedListNode<int> *temp=head, *tempNext=head->next;
    while(temp!=NULL)
    {
        LinkedListNode<int> *clone=new LinkedListNode<int>(temp->data);
        temp->next=clone;
        clone->next=tempNext;
        temp=tempNext;
        if(tempNext!=NULL)
            tempNext=tempNext->next;
    }

}

void handleRandomPointers(LinkedListNode<int> *head)
{
    LinkedListNode<int> *temp=head;
    while(temp)
    {
        if(temp->random !=NULL)
            temp->next->random=temp->random->next;
        else
            temp->next->random=NULL;
            
        temp=temp->next->next;
    }
}

LinkedListNode<int> *cloneList(LinkedListNode<int> *head)
{
    LinkedListNode<int> *ans=head->next;
    LinkedListNode<int> *t1=head,*t2=ans;

    while(t1!=NULL)
    {
        t1->next=t2->next;
        t1=t1->next;
        if(t1==NULL)break;
        t2->next=t1->next;
        t2=t2->next;
    }
    return ans;
}
LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head)
{
    if(head==NULL)return NULL;//edge case

    //create copyList
    copyList(head);
    
    //handle Random pointers
    handleRandomPointers(head);

    //separate original and clone list and return cloneList
    return cloneList(head);
}

n

/*
BETTER : HASHING

LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head)
{
    if(head==NULL)return head;
    unordered_map< LinkedListNode<int>*,LinkedListNode<int>*> mpp;
    LinkedListNode<int> *temp=head;
    LinkedListNode<int> *ans,*cloneNode;
    //creating only new clone nodes and mapping (no connections now)
    while(temp!=NULL)
    {
        LinkedListNode<int> *clone=new LinkedListNode<int>(temp->data);
        mpp[temp]=clone;
        temp=temp->next;
    }
    temp=head;
    ans=mpp[head];

//make next and random connections
    while(temp!=NULL)
    {
        cloneNode=mpp[temp];
        cloneNode->next = mpp[temp->next];
        cloneNode->random=mpp[temp->random];
        // cloneNode=cloneNode->next;
        temp=temp->next;
    }
    return ans;
}


*/