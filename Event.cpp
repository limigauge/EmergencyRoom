#include "Event.h"

/*
 * CLASS: Event.cpp
 *
 * Author: Michelle Li
 *
 * REMARKS: Implementation file for Event class. Super class of the three types of events: Arrival, Prepare, and CompleteService.
 * Stores the main inherited fields for its subclasses and contains getter methods for these fields.
 *
 * ---------------------------------------------------------------------------------------
 */

Event::Event(){
    //default constructor
}

Event::Event(int ID, FoodOrder* food, int arrival, int expiry, int extras, int completionTime){
    this->ID = ID;
    meal = food;
    arrivalTime = arrival;
    this->expiry = expiry;
    prepTime = food->getTime() + extras;
    price = food->getPrice() + extras;
    ingredients = extras;
    this->completionTime = completionTime;

} //constructor


//GETTER METHODS:

int Event::getExpiry() {
    return expiry;
}

int Event::getArrival() {
    return arrivalTime;
}

int Event::getID(){
    return ID;
}

int Event::getPrepTime() {
    return prepTime;
}

bool Event::isExpired(int currTime) {
    bool expired = false;

    if(expiry < currTime){
        //passed expiry time
        expired = true;
    } //check expiry (if current time is greater than expiry time.

    return expired;
}

double Event::getPrice() {
    return price;
}

FoodOrder* Event::getMeal(){
    return meal;
}

int Event::getIngredients() {
    return ingredients;
}

int Event::getCompletionTime(){
    return completionTime;
}

void Event::message(int){
//virtual for polymorphism
}