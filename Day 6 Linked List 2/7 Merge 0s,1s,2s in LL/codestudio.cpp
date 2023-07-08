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

Node* sortList(Node *head){
    //Approach 2: data replacement N O T allowed
    Node* h0=NULL,*t0=NULL,*h1=NULL,*t1=NULL,*h2=NULL,*t2=NULL;
    Node* temp=head;

    while(temp!=NULL)
    {
        int val=temp->data;
        if(val==0)
        {
            if(h0==NULL)
            {
                h0=temp;
                t0=temp;
            }
            else{
                t0->next=temp;
                t0=temp;
            }
        }
        else if(val==1)
        {
            if(h1==NULL)
            {
                h1=temp;
                t1=temp;
            }
            else{
                t1->next=temp;
                t1=temp;
            }
        }
        else{
            //val=2
            if(h2==NULL)
            {
                h2=temp;
                t2=temp;
            }
            else{
                t2->next=temp;
                t2=temp;
            }
        }
        temp=temp->next;
    }
    
    //now temp is at null
    //decide head that we have to return
    if(h0!=NULL)
        head=h0;
    else if(h1!=NULL)
        head=h1;
    else
    {
        head=h2;
        return head;
    }

    //make connections 
    if(t0!=NULL)
    {
        if(h1!=NULL)
            t0->next=h1;
        else
            t0->next=h2;
    }
    if(t1!=NULL)
    {
        if(h2!=NULL)
            t1->next=h2;
        else
            t1->next=NULL;
    }
    if(t2!=NULL)
    {
        t2->next=NULL;
    }

    return head;








    
    //Approach 1: data replacement allowed
    /*
    Node* temp=head;
    int cnt0=0,cnt1=0,cnt2=0;
    while(temp!=NULL)
    {
        if(temp->data == 0)
            cnt0++;
        else if(temp->data == 1)
            cnt1++;
        else if(temp->data == 2)
            cnt2++;
        temp=temp->next;
    }
    temp=head;
    while(cnt0>0)
    {
        temp->data=0;
        temp=temp->next;
        cnt0--;
    }
    while(cnt1>0)
    {
        temp->data=1;
        temp=temp->next;
        cnt1--;
    }
    while(cnt2>0)
    {
        temp->data=2;
        temp=temp->next;
        cnt2--;
    }
    return head;
    */
}