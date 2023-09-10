#pragma once
#include "Node.h"
#include "Queue.h"
#include "Event.h"

/*
 * CLASS: PriorityQueue.h
 *
 * Author: Michelle Li
 *
 * REMARKS: Header file for PriorityQueue.cpp
 *
 * ---------------------------------------------------------------------------------------
 */

class PriorityQueue : public Queue{

public:
    virtual void insert(Event*) = 0; //different for priority queue
    PriorityQueue();
};