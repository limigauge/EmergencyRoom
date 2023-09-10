#pragma once
#include "PriorityQueue.h"
#include "Event.h"

/*
 * CLASS: PQTime.h
 *
 * Author: Michelle Li
 *
 * REMARKS: Header file for PQTime.cpp.
 *
 * ---------------------------------------------------------------------------------------
 */

class PQTime : public PriorityQueue{
public:
    PQTime();
    void insert(Event*);
};
