#include <iostream>
#include "NumberArray.h"//Contained an external file
using namespace std;
int main(){
    int howMany;
    int count;
    double val;
    cout << "How many numbers do you want to store? ";
    cin >> howMany;

    NumberArray numbers(howMany);

    cout << "Enter the " << howMany << " numbers: ";
    for(count = 0; count < howMany; count++){
        cout << "Number " << (count + 1) << ": ";
        cin >> val;
        
        numbers.setCell(count, val);
    }

    cout << "Here are the numbers you entered:\n";
    for(count = 0; count < howMany; count++){
        cout << "Number " << (count + 1) << ": " << numbers.getCell(count) << endl; 
    }
    cout << "The average of those numbers is: ";
    cout << numbers.getAverage() << endl;

    cout << "The highest of those numbers is: ";
    cout << numbers.getHighest() << endl;

    cout << "The lowest of those numbers is: ";
    cout << numbers.getlowest() << endl;
    return 0;
}
