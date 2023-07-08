/********************************************************************

    Following is the representation of the Singly Linked List Node:

    class node{
        public:
            int data;
            node * next;
            node(int data){
                this->data=data;
                this->next=NULL;
            }
    };
    
********************************************************************/
node* findMid(node* head)
{
    if(head==NULL || head->next==NULL)return head;
    node* slow=head,*fast=head->next;
    while(fast!=NULL && fast->next!=NULL )
    {
        //u get 1st mid element in case of even no. nodes
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}

node* merge(node* left,node* right)
{
    if(left==NULL)
        return right;
    if(right==NULL)
        return left;
    
    node* ans=new node(-1);
    node* temp=ans;
    //merging 
    while(left!=NULL && right!=NULL)
    {
        if(left->data < right->data)
        {
            temp->next=left;
            temp=left;
            left=left->next;
        }   
        else
        {
            temp->next=right;
            temp=right;
            right=right->next;
        }
    }
    //if right sorted ll has exhausted but not left ll
    while(left!=NULL)
    {
        temp->next=left;
        temp=left;
        left=left->next;
    }
    //if left sorted has exhausted but not right ll
    while(right!=NULL)
    {
        temp->next=right;
        temp=right;
        right=right->next;
    }
    ans=ans->next;
    return ans;

}
node* mergeSort(node *head) {
    //base case
    if(head==NULL || head->next==NULL)return head;

    node* mid=findMid(head);

    //break LL into two halves after fimding middle node
    node* left=head;
    node* right=mid->next;
    mid->next=NULL;
    //recursively perform merge sort on both halves
    left=mergeSort(left);
    right=mergeSort(right);

    node* result=merge(left,right);
    return result;
}
