#pragma once
#include "Node.h"
#include "List.h"

/*
 * CLASS: Stack.h
 *
 * Author: Michelle Li
 *
 * REMARKS: header file for Stack.cpp.
 *
 * ---------------------------------------------------------------------------------------
 */

class Stack : public List{

public:
    Stack();
    Node* pop();
    Node* peek();
};
