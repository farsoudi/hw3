#include "llrec.h"
#include <iostream>

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot) {
    if (!head) {
        return;
    }

    Node* next = head->next;
    if (head->val <= pivot) {
        #ifdef DEBUG
        std::cout << "Adding " << head->val << " to smaller list" << std::endl;
        #endif
        head->next = smaller;
        smaller = head;
    } else {
        #ifdef DEBUG
        std::cout << "Adding " << head->val << " to larger list" << std::endl;
        #endif
        head->next = larger;
        larger = head;
    }
    head = nullptr;
    llpivot(next, smaller, larger, pivot);
}


