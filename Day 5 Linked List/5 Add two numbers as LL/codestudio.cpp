/**
 * Definition of linked list:
 *
 * class Node {
 * public:
 *      int data;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next) {
 *          this->data = data;
 *          this->next = next;
 *      }
 * };
 *
 *************************************************************************/

Node *addTwoNumbers(Node *num1, Node *num2)
{
    int sum=0,carry=0;
    Node * ans=new Node();
    //edge case : both list empty
    if(num1==NULL && num2==NULL)return ans;
    Node*temp=ans;
    Node*l1=num1;
    Node*l2=num2;
    while(true)
    {
        int a=0,b=0;
        if(l1!=NULL) a=l1->data;
        if(l2!=NULL) b=l2->data;
        if(a==0 && b==0 && carry==0 && l1==NULL && l2==NULL)
        {
            //no need to create new node, we are done
            break;
        }

        sum=a+b+carry;
        if(sum>9)
        {
            carry=sum/10;
            sum=sum%10;
        }
        else //sum<=9
            carry=0;
        
        Node * nextNode=new Node(sum);
        temp->next=nextNode;
        temp=nextNode;

        if(l1!=NULL) l1=l1->next;
        if(l2!=NULL) l2=l2->next;

    }
    return ans->next;
}














