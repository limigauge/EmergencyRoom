#pragma once
#include "Event.h"

/*
 * CLASS: CompleteService.h
 *
 * Author: Michelle Li
 *
 * REMARKS: Header file for CompleteService.cpp.
 *
 * ---------------------------------------------------------------------------------------
 */

class CompleteService : public Event{

public:
    CompleteService(int, FoodOrder*, int, int, int, int);
    void message(int);
};