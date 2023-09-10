#pragma once
#include "Node.h"
#include "List.h"

/*
 * CLASS: Queue.h
 *
 * Author: Michelle Li
 *
 * REMARKS: Header file for Queue.cpp
 *
 * ---------------------------------------------------------------------------------------
 */

class Queue : public List{

public:
    Queue();
    Node* dequeue();
    Node* peek();
};
