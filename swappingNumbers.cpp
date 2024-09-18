#include<iostream>
using namespace std;

float exchangeNumbers(float&, float&);

int main(){
    float num1 = 0, num2 = 0;

    cout <<" Please input the value of number 1: ";
    cin >> num1;

    cout << "Please input the value of number 2: ";
    cin >> num2;

    cout << "You input the numbers as: " << num1 <<  " and " << num2 << endl;

    exchangeNumbers(num1, num2);

    cout << "After swapping, the first number entered has the value of: " << num1 << ", which is the value of Number 2." << endl;
    cout << "The scecond number now has the value of " << num2 << ", which is the value of number 1." << endl;

    return 0;
}

float exchangeNumbers(float& number1, float& number2){
    float x = number1;
    number1 = number2;
    number2 = x;
    return number1, number2;
}