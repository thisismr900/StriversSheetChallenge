/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    private:
    ListNode *reverse(ListNode *head)
    {
        if(head==NULL || head->next==NULL)return head;
        ListNode *prev=NULL,*curr=head,*nex;
        while(curr!=NULL)
        {
            nex=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nex;
        }
        return prev;
    }
public:
    bool isPalindrome(ListNode* head) {
        bool result=true;
        if(head==NULL|| head->next==NULL)return true;
        
        //step1 : find middle
        ListNode *slow=head,*fast=head,*middle;
        
        while(fast->next!=NULL && fast->next->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        middle=slow;
        
        //step 2 : reverse the LL after middle
        middle->next=reverse(middle->next);
        
        //step 3: compare both halves
        ListNode *t1=head,*t2=middle->next;
        while(t2!=NULL)
        {
            if(t1->val != t2->val)
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
};