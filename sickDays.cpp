#include<iostream>
using namespace std;

int main(){
    int tellers = 0, years = 3, sickDays = 0, totalSickdays = 0;

    cout << "How many tellers worked at Nation's Bank during each of the last three years? ";
    cin >> tellers;

    for (int i = 0; i < tellers; i++){
        for (int y = 0; y < years; y++){
            cout << "How many days was teller " << i + 1 << " out sick during the year " << y + 1 << "? ";
            cin >> sickDays;

            totalSickdays += sickDays;
            sickDays = 0;
        }
    }
    cout << "The " << tellers << " tellers were out sick for a total of " << totalSickdays << " during the last " << years << " years";

    return 0;
}