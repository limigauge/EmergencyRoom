#pragma once
#include "Node.h"

//testing with print method
#include <iostream>
using namespace std;

/*
 * CLASS: List.h
 *
 * Author: Michelle Li
 *
 * REMARKS: Header file for List.cpp
 *
 * ---------------------------------------------------------------------------------------
 */

class List{
protected:
    Node* top;
    Node* tail;

public:
    void insert(Event*); //string for testing change to Event or something later
    List();
    virtual Node* peek();
    void print();
};
