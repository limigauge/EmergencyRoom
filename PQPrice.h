#pragma once
#include "PriorityQueue.h"
class Event; //fr

/*
 * CLASS: PQPrice.h
 *
 * Author: Michelle Li
 *
 * REMARKS: Header file for PQPrice.cpp.
 *
 * ---------------------------------------------------------------------------------------
 */

class PQPrice : public PriorityQueue{
public:
    PQPrice();
    void insert(Event*);
};
