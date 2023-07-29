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

Node *rotate(Node *head, int k) {
     // Write your code here.
     if(k==0 || head==NULL) return head;
     
     int nodesCount=0;
     Node*temp=head,*tail=NULL;
     while(temp!=NULL)
     {
          nodesCount++;
          tail=temp;
          temp=temp->next;
     }
     k=k%(nodesCount);
     int x=nodesCount-k;
     temp=head;
     while(x>1)
     {
          temp=temp->next;
          x--;
     }
     if(temp->next==NULL)return head;
     
     Node*newHead=temp->next;
     
     tail->next=head;
     temp->next=NULL;
     return newHead;

}