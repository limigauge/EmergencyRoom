#include "FoodOrder.h"
using namespace std;

/*
 * CLASS: FoodOrder.cpp
 *
 * Author: Michelle Li
 *
 * REMARKS: Implementation file for FoodOrder class. Superclass that stores fields for the three types of food to order.
 *
 * ---------------------------------------------------------------------------------------
 */

void FoodOrder::polymorphic() {
//virtual method
}

FoodOrder::FoodOrder(){
    //default constructor
}

FoodOrder::FoodOrder(string name, double price, int time){

    this->name = name;
    basePrice = price;
    baseTime = time;

} //constructor

//GETTER METHODS:

string FoodOrder::getName(){
    return name;
}

double FoodOrder::getPrice(){
    return basePrice;
}

int FoodOrder::getTime(){
    return baseTime;
}
