//
// Created by jplip on 2/14/2026.
//
#include <iostream>
using namespace std;

const int elementSize = 100000;

//Linear Search
int linearSearch(int theArray[], int theInput, int &theSteps){
    theSteps = 0;

    for(int i=0; i<elementSize; i++){
        theSteps++;

        if(theArray[i] == theInput)
            return i;
    }

    //Return -1 not found
    return -1;
}

//Binary Search
int binarySearch(int A[], int n, int T, int &theSteps){
    int left = 0;
    int right = n - 1;
    theSteps = 0;

    while(left <= right){
        int middle = (left + right)/2;
        theSteps++;

        if(A[middle] < T)
            left = middle + 1;
        else if(A[middle] > T)
            right = middle - 1;
        else
            return middle;
    }

    //Return -1 not found
    return -1;
}

int main(){
    int array[elementSize];
    int input;
    int linearSteps;
    int binarySteps;

    //Fill array
    for(int i=0; i<elementSize; i++)
        array[i] = i;

    //Input
    cout << "Enter value to search:";
    cin >> input;

    //Calling functions
    int linearResult = linearSearch(array, input, linearSteps);
    int binaryResult = binarySearch(array, elementSize, input, binarySteps);

    //Outputs
    if(linearResult == -1)
        cout << "Linear search: Value not found." << endl;
    else
        cout << "Linear search steps: " << linearSteps << endl;

    if(binaryResult == -1)
        cout << "Binary search: Value not found." << endl;
    else
        cout << "Binary search steps: " << binarySteps << endl;

    //Return 0 success
    return 0;
}