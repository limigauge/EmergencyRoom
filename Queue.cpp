#include "Queue.h"

/*
 * CLASS: Queue.cpp
 *
 * Author: Michelle Li
 *
 * REMARKS: Subclass of List. A queue implemented with Linked Lists. Contains the dequeue method to dequeue the item at the top of the list.
 * (Oldest item). Is the superclass of the more specific PriorityQueue.
 *
 * ---------------------------------------------------------------------------------------
 */


Queue::Queue() : List(){
}//constructor

/* ---------------------------------------------------------------------------------------
 *  dequeue()
 *
 *  PURPOSE: Dequeues the Node at the top of the List (removes and deletes it)

 *  RETURNS: The Node that was dequeued.
 *
 *  ---------------------------------------------------------------------------------------
 */

Node* Queue::dequeue(){
    Node * out;
    Node * curr = tail;

    if(top == nullptr) {
        //no items in list
        out = nullptr;
    } else if(top == tail){
        //only one item in queue
        out = top;
        top = nullptr;
        tail = nullptr;
    } else {
        while(curr->getNext() != top) {
            curr = curr->getNext();
        } //keep going until the node after curr is TOP (curr is 2nd node)

        out = top;
        top = curr;
        top->setNext(nullptr);
    }

    return out;
}

Node* Queue::peek() {
    return top;
}
