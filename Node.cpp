#include "Node.h"

/*
 * CLASS: Node.h
 *
 * Author: Michelle Li
 *
 * REMARKS: Implementation file for Node class. Each Node contains an event as its content. Also contains getter and setter methods
 * for next node, and its contents.
 *
 * ---------------------------------------------------------------------------------------
 */

Node::Node(Node* next, Event* order){
    this->next = next;
    content = order;
} //constructor

//GETTER AND SETTERS:
Node* Node::getNext() {
    return next;
}

void Node::setNext(Node* newNode) {
    next = newNode;
}

Event* Node::getItem(){
    return content;
}




