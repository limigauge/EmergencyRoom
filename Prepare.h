#pragma once
#include "Event.h"

/*
 * CLASS: Prepare.h
 *
 * Author: Michelle Li
 *
 * REMARKS: Header file for Prepare.cpp.
 *
 * ---------------------------------------------------------------------------------------
 */

class Prepare : public Event{

public:
    Prepare(int, FoodOrder*, int, int, int, int);
    void message(int);
};