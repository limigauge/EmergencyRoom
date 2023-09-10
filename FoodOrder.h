#pragma once
#include <string>

using namespace std;

/*
 * CLASS: FoodOrder.h
 *
 * Author: Michelle Li
 *
 * REMARKS: Header file for FoodOrder.cpp
 *
 * ---------------------------------------------------------------------------------------
 */

class FoodOrder{

private:
    string name;
    float basePrice;
    int baseTime;

public:
    FoodOrder();
    FoodOrder(string, double, int); //get type
    virtual void polymorphic();
    string getName();
    double getPrice();
    int getTime();

};
