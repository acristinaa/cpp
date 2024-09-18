#include<iostream>
using namespace std;

double median(int *, int);
int mode(int *, int);
int *makeArray(int);
void getData(int *, int);
void selectionSort(int[],int);
double avg(int *, int);

int main(){
    int *movieData, num, mod;
    
    cout << "How many students were surveyed? ";
    cin >> num;

    movieData = makeArray(num);
    getData(movieData, num);
    selectionSort(movieData, num);

    cout << "The average of movies seen is: " << avg(movieData, num) << endl;
    cout << "The median of the number of movies seen is: " << median(movieData, num) << endl;
    cout << "The mode of number of movies seen is: ";
    mod = mode(movieData, num);

    if(mod == -1){
        cout << "The set has no mode." << endl;
    }else{
        cout << "The mode is: " << mod << endl;
    }

    delete [] movieData;
    movieData = 0;

    return 0;
}

int *makeArray(int size){
    int *ptr;
    ptr = new int[size];
    return ptr;
}

void getData(int arr[], int num){
    cout << "Enter the number of movies that each student watched:\n";

    for(int i = 0; i < num; i++){
        cout << "student " << (i+1) << ": ";
        cin >> arr[i];
    }
}

void selectionSort(int values[], int size){
    int startScan, minIndex, minValue;

    for(startScan = 0; startScan < (size - 1); startScan++){
        minIndex = startScan;
        minValue = values[startScan];

        for(int index = startScan + 1; index < size; index++){
            if(values[index] < minValue){
                minValue = values[index];
                minIndex = index;
            }
        }
        values[minIndex] = values[startScan];
        values[startScan] = minValue;
    }
}

double median(int *arr, int num){
    double med;
    int mid1, mid2;
    if(num % 2 == 0){
        mid1 = num / 2;
        mid2 = (num / 2) - 1;
        med = ((*(arr + mid1)+ *(arr + mid2)) / 2.0);
    }else{
        med = *(arr + (num / 2));
    }
    return med;
}

int mode(int *arr, int num){
    int *freq, highest, element, count;
    freq = makeArray(num);

    for(count = 0; count < num; count++){
        freq[count] = 0;
    }
    for(int count1 = 0; count1 < num; count1++){
        for(int count2 = 0; count2 < num; count2 ++){
            if(*(arr + count2) == *(arr + count1)){
                (*(freq + count1))++;
            }
        }
    }
    highest = *freq;
    element = 0;

    for(count = 1; count < num; count++){
        if(*(freq + count) > highest){
            highest = *(freq + count);
            element = count;
        }
    }

    if(highest == 1){
        return -1;
    }else{
        return *(arr + element);
    }
}

double avg(int arr[], int num){
    int total = 0;
    double average;

    for(int count = 0; count < num; count++){
        total += arr[count];
    }

    average = total / static_cast<double>(num);

    return average;
}