#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

class Stack
{
public:
    Stack();
    Stack(int maxSize);
    ~Stack();

    void push(double data);
    double pop();
    double peek();

    bool isEmpty();
    bool isFull();
    int getSize();
    void print();

private:
    int top;
    int mSize;
    double *myArray;
    int mySize;
};

#endif

