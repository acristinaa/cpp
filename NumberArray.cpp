#include<iostream>
#include "NumberArray.h"
using namespace std;

NumberArray::NumberArray(int s){
    arrayPointer = nullptr;
    arrayPointer = new double[s];
    size = s;
}
Number::~NumberArray(){
    if(arrayPointer != nullptr){
        delete[] arrayPointer;
        arrayPointer = nullptr;
    }
}
void NumberArray::setCell(int c, double val){
    if(arrayPointer != nullptr && c >= 0 && c<= size){
        arrayPointer[c] = val;
    }else{
        cout << "Invalid cell number...\n";
        exit[EXIT_FAILURE];
    }
}
int NumberArray::getCell(int cellNum){
    if(cellNum < 0 || cellNum > size){
        cout << "Invalid cell number...\n";
        exit[EXIT_FAILURE];
    }
    return arrayPointer[cellNum];
}
double NumberArray::getAverage(){
    double total = 0;
    for(int count = 0; count < size; count++){
        total += arrayPointer[count];
    }
    return total/size;
}
double NumberArray::getHigher(){
    double highest = arrayPointer[0];
    for(int count = 1; count < size; count++){
        if(arrayPointer[count] > highest){
            highest = arrayPointer[count];
        }
    }
    return highest;
}
double NumberArray::getLowest(){
    double lowest = arrayPointer[0];
    for(int count = 1; count < size; count++){
        if(arrayPointer[count] < lowest){
            lowest = arrayPointer[count];
        }
    }
    return lowest;
}