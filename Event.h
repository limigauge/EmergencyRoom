#pragma once
#include <string>
#include "FoodOrder.h"
#include <iostream>

using namespace std;

/*
 * CLASS: Event.h
 *
 * Author: Michelle Li
 *
 * REMARKS: Header file for Event.cpp.
 *
 * ---------------------------------------------------------------------------------------
 */

class Event{

protected:
    int ID;
    int ingredients;
    FoodOrder* meal;
    int arrivalTime;
    int expiry; //can be automatically set to arrivalTime + expiryTime to get exact time of expiry.
    double price; //base price + 1 for each extra
    int prepTime; //base time + 1 for each extra
    int completionTime;

public:

    Event();
    Event(int, FoodOrder*, int, int, int, int); //ID, meal, arrivalTime, expiry time, number of extras, completionTime
    double getPrice();
    int getArrival();
    int getExpiry();
    int getPrepTime();
    bool isExpired(int);
    int getID();
    FoodOrder* getMeal();
    int getIngredients();
    int getCompletionTime();

    virtual void message(int);
};