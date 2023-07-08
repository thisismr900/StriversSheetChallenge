Node* merge(Node* left, Node* right)
{
    if(left==NULL)return right;
    if(right==NULL)return left;
    Node*ans=new Node();
    Node*temp=ans;

    while(left!=NULL && right!=NULL)
    {
        if(left->data <= right->data)
        {
            temp->child=left;
            temp=left;
            left=left->child;
        }
        else{
            temp->child=right;
            temp=right;
            right=right->child;
        }
    }

    if(left==NULL)
        temp->child=right;
    if(right==NULL)
        temp->child=left;
    
    return ans->child;

}
Node* flattenLinkedList(Node* head) 
{
    if(head==NULL || head->next==NULL)return head;
    Node* down=head;
    Node* right=flattenLinkedList(head->next);
    down->next=NULL;
    Node* ans=merge(down,right);
    return ans;
}
