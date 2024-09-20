#include<iostream>
using namespace std;

int main(){
    int coffee = 0, tea = 0, coke = 0, orangeJuice = 0;
    int choice = 0;
    int num = 0;

    cout << "BEVERAGE CHOICES: \n" << endl;
    cout << "1. Coffee, 2. Tea, 3. Coke, 4. Orange Juice \n" << endl;

    while(choice != -1){
        cout << "Please type the favorite bevearge of person #" << num + 1 << endl;

        cout << "Pick 1, 2, 3 or 4 from the menu above. Or -1 to exit the program. " << endl;
        cin >> choice;

    if(choice == 1){
        coffee++;
    }
    else if(choice == 2){
        tea++;
    }
    else if(choice == 3){
        coke++;
    }
    else if(choice == 4){
        orangeJuice++;
    }
    else if(choice == -1){
        exit(-1);
    }
    num++;
    }
    cout << "The total number of people on this survey is: " << num << endl;
    cout << "The results are: " << endl;
    cout << "Beverage number of votes: \n";
    cout << "********************************";
    cout << "1. Coffee: " << coffee << endl;
    cout << "2. Tea: " << tea << endl;
    cout << "3. Coke: " << coke << endl;
    cout << "4. Orange Juice: " << orangeJuice << endl;

    return 0;
}