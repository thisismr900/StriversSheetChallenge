/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *head1, ListNode *head2) {
        if(head1==NULL || head2==NULL) return NULL;//edge case 

        ListNode *h1=head1;
        ListNode *h2=head2;
        ListNode *ansNode=NULL;

        while(h2!= NULL)
        {
            h1=head1;
            while(h1!= NULL)
            {
                if(h1==h2){
                    ansNode=h1;
                    break;
                }

                h1=h1->next;
            }
            if(ansNode!=NULL)break;
            h2=h2->next;
        }
        return ansNode;
    }
};