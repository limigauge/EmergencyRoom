#include "PriorityQueue.h"
#include "Queue.h"

/*
 * CLASS: PriorityQueue.h
 *
 * Author: Michelle Li
 *
 * REMARKS: Implementation file for PriorityQueue, which is mostly just for being a superclass of PQTime and PQPrice for insertions depending
 * on factor (Time or Price)
 *
 * ---------------------------------------------------------------------------------------
 */

PriorityQueue::PriorityQueue() : Queue(){
}//constructor

void PriorityQueue::insert(Event *e){
    //polymorphic method
}


