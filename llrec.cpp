#include "llrec.h"
#include <iostream>

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot)
{
    smaller = nullptr;
    larger = nullptr;

    Node* smallerTail = nullptr;
    Node* largerTail  = nullptr;

    Node* curr = head;
    while (curr != nullptr)
    {
        Node* nextNode = curr->next;

        curr->next = nullptr;

        if (curr->val <= pivot)
        {
            if (smaller == nullptr)
            {
                smaller = curr;
                smallerTail = curr;
            }
            else
            {
                smallerTail->next = curr;
                smallerTail = curr;
            }
        }
        else
        {
            if (larger == nullptr)
            {
                larger = curr;
                largerTail = curr;
            }
            else
            {
                largerTail->next = curr;
                largerTail = curr;
            }
        }

        curr = nextNode;
    }

    head = nullptr;
}


