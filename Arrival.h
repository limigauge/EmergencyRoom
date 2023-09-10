#pragma once
#include "Event.h"
#include <string>

/*
 * CLASS: Arrival.h
 *
 * Author: Michelle Li
 *
 * REMARKS: Header file for class Arrival.cpp.
 *
 * ---------------------------------------------------------------------------------------
 */

class Arrival : public Event{
public:
    Arrival(int, FoodOrder*, int, int, int, int);
    void message(int);
};