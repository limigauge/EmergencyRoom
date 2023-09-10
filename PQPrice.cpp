#include "PQPrice.h"

/*
 * CLASS: PQPrice.cpp
 *
 * Author: Michelle Li
 *
 * REMARKS: Implementation for a price based Priority Queue (subclass of PriorityQueue). Insertion is specialized so the highest priced
 * orders are the highest priority. Name is PriorityQueuePrice but shortened...
 *
 * ---------------------------------------------------------------------------------------
 */

PQPrice::PQPrice() {
    Queue();
} //constructor

/* ---------------------------------------------------------------------------------------
 *  insert(Event*)
 *
 *  PURPOSE: Inserts a new Event* for an order into the Priority Queue based on the price of the order to insert.
 *  Higher price means higher priority.
 *  PARAMETERS:
 *  Event * order - the event to insert.
 *
 *  ---------------------------------------------------------------------------------------
 */

void PQPrice::insert(Event * order){
    Node * newNode = new Node(nullptr, order);
    Node * curr = tail;
    Node * prev = nullptr;

    if(curr == nullptr){
        //first item
        top = newNode;
        tail = top;
    } else {
        while(curr != nullptr && order->getPrice() > curr->getItem()->getPrice()){
            //while not at end of list, and curr node's order's price is less than newNode's

            prev = curr;
            curr = curr->getNext();
        } //exit loop means either 1) at top of list, 2) curr node's price is GREATER than newNode's

        if(prev == nullptr){
            //insert at end of list

            newNode->setNext(tail);
            tail = newNode;

        } else if (curr == nullptr) {
            //top of list

            top->setNext(newNode);
            top = newNode;
        }  else {

            newNode->setNext(curr);
            prev->setNext(newNode);
        } //insert in between curr and prev nodes

    }
}


