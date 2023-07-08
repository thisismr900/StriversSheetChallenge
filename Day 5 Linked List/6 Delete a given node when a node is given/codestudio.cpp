#include <bits/stdc++.h>

/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/
//dumb solution
void deleteNode(LinkedListNode<int> * node) {
    // Write your code here.
    node->data=node->next->data;
    LinkedListNode<int>*gaya=node->next;
    node->next=gaya->next;
}