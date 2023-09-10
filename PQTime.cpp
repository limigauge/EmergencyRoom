#include "PQTime.h"

/*
 * CLASS: PQTime.cpp
 *
 * Author: Michelle Li
 *
 * REMARKS: Implementation file for a time dependant priority queue (subclass of PriorityQueue). Insertion is specialized to insert
 * highest priority by lowest time (first come first serve)
 *
 * ---------------------------------------------------------------------------------------
 */

PQTime::PQTime() {
    Queue();
}

/* ---------------------------------------------------------------------------------------
 *  insert(Event*)
 *
 *  PURPOSE: Inserts a new Event* for an order into the Priority Queue based on the time of the order to insert.
 *  Lower time means higher priority. (first come first serve)
 *  PARAMETERS:
 *  Event * order - the event to insert.
 *
 *  ---------------------------------------------------------------------------------------
 */

void PQTime::insert(Event * order){
    Node * newNode = new Node(nullptr, order);
    Node * curr = tail;
    Node * prev = nullptr;

    if(curr == nullptr){
        //first item
        top = newNode;
        tail = top;
    } else {
        while(curr != nullptr && order->getCompletionTime() < curr->getItem()->getCompletionTime()){
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


