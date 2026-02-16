//
// Created by jplip on 2/15/2026.
//
#include <iostream>
#include <vector>
#include <random>
using namespace std;

const int elementSize = 100000;

int randomSearch(const vector<int>& theSet, int theValue, int &theComparisons){
    theComparisons = 0;
    vector<bool> visited(elementSize, false);

    random_device seed;
    mt19937 gen(seed());
    uniform_int_distribution<> dist(0, elementSize - 1);

    theComparisons = 0;
    int remaining = elementSize;

    while(remaining > 0){
        int index = dist(gen);

        if(!visited[index]){
            visited[index] = true;
            theComparisons++;

            if(theSet[index] == theValue)
                return index;

            remaining--;
        }
    }

    //Return -1 not found
    return -1;
}

int main(){
    vector<int> set(elementSize);
    int input;
    int randomComparisons;

    //Fill vector
    for(int i=0; i<elementSize; i++)
        set[i] = i;

    //Input
    cout << "Enter value to search for:";
    cin >> input;

    //Calling function
    int randomResult = randomSearch(set, input, randomComparisons);

    //Output
    if(randomResult == -1)
        cout << "Value not found." << endl;

    cout << "Comparisons performed: " << randomComparisons << endl;

    //Return 0 success
    return 0;
}