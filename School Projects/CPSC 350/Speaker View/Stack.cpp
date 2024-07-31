#include "Stack.h"

Stack::Stack(){
    mSize = 64;
    top = -1;
    myArray = new double[mSize];

}

Stack::Stack(int maxSize){
    mSize = maxSize; 
    top = -1;
    myArray = new double[mSize];
}

Stack::~Stack(){
    cout << "stack destroyer" << endl;
    delete[] myArray;
}

void Stack::push(double data) {
        if (isFull()) {
            double *temp = new double[2 * mSize];
            for (int i = 0; i <= top; ++i) {
                temp[i] = myArray[i];
            }
            mSize *= 2;
            delete[] myArray;
            myArray = temp;
        }
        while (top >= 0 && myArray[top] < data) {
            --top;
        }

        myArray[++top] = data;
    }

double Stack::pop(){

    if(isEmpty()){
        throw runtime_error("stack is empty, nothing to remove");
    }

    return myArray[top];
}

double Stack::peek(){
    if(isEmpty()){
        throw runtime_error("stack is empty, nothing to see here");
    }
    return myArray[top];
}

bool Stack::isFull(){
    return (top == mSize-1);

}

bool Stack::isEmpty(){
    return (top == -1);
}

int Stack::getSize(){
    return top + 1;
}

void Stack::print(){
    for (int i = 0; i < getSize() ; i++){
        cout << myArray[i] << " ";
    }
    cout << endl;
    
}
