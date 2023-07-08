/****************************************************************

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

*****************************************************************/

Node* findIntersection(Node *head1, Node *head2)
{
    Node *l1=head1;
    Node *l2=head2;

    while(l1!=NULL && l2!=NULL)
    {
        if(l1==l2)return l1;  //if both linked list are of equal length
        l1=l1->next;
        l2=l2->next;
    }

    int extraNodes=0;
    //case 1 :only  l1=null
    if(l1==NULL && l2!=NULL) //length of l2 is greater
    {
        while(l2!=NULL)
        {
            extraNodes++;
            l2=l2->next;
        }//l2=null
        l2=head2;
        l1=head1;
        while(extraNodes>0)
        {
            l2=l2->next;
            extraNodes--;
        }
        //now length of l2 equals l1
    } 

        //case 2 :only  l2=null
    else if(l2==NULL && l1!=NULL) //length of l1 is greater
    {
        while(l1!=NULL)
        {
            extraNodes++;
            l1=l1->next;
        }//l1=NULL
        l1=head1;
        l2=head2;
        while(extraNodes>0)
        {
            l1=l1->next;
            extraNodes--;
        }
        //now length of l1 equals l2
    } 


    //after one of these two cases , l1 and l2 are placed such that its length are equal 
    while(l1!=l2)
    {
        l1=l1->next;
        l2=l2->next;
    }

    return l1;
    
}