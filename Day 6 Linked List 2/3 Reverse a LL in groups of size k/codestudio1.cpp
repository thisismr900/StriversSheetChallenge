/**
 * Definition for singly-linked list.
 * class Node {
 * public:
 *     int data;
 *     Node *next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node *next) : data(x), next(next) {}
 * };
 */
void reverse(Node*start, Node*end)
{
    Node* prev=NULL;
    Node* curr=start;
    while(prev!=end)
    {
        Node* nex=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nex;
    }

}


Node* kReverse(Node* head, int k) {
/*ITERATIVELY optimal
TC: O(n)
SC:O(1)
*/
    Node* dummy=new Node(-1,head);
    int nodesCount=0;
    Node* end=head;
    Node* beforeStart=dummy;
    while(end!=NULL)
    {
        nodesCount++;
        if(nodesCount%k ==0)
        {
            //reversal of the group:[start  se lekar end tak]
            Node* start=beforeStart->next;
            Node* afterEnd=end->next;

            reverse(start,end);
            //make connections after reversal of [start-end]
            beforeStart->next=end;
            start->next=afterEnd;
            //all done, now update end and before start so as to do for next group
            end=afterEnd;
            beforeStart=start;
            // nodesCount=0;
        }
        else{
            end=end->next;
        }
    }

    return dummy->next;

















/*  recursively
TC: O(n)
SC:O(n)
    int cnt=k;
    Node * temp=head;
    while(temp!=NULL && cnt>0)
    {
        temp=temp->next;
        cnt--;
    }
    if(cnt!=0)//no need to reverse this group having less than k nodes
        return head;

    //reverse the first k group
    Node*curr=head;
    Node*prev=NULL;
    cnt=k;
    while(cnt>0)
    {
        temp=curr->next;
        curr->next=prev;
        prev=curr;
        curr=temp;
        cnt--;
    }
    //recursively reverse remaining list
    head->next=kReverse(curr, k);

    return prev;
    */
}