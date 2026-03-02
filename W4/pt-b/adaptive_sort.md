# Activity 4b Adaptive sorting

## Questions
### Part A:
This code will make an array size of 50 and fill it with randomly generated numbers. It will then analyze that array to see which case type it is to use between Selection Sort and Insertion Sort.
```c++
#include <iostream>
using namespace std;

const int elementSize = 50;

//Analyzation of array
string analyzeArray(int theArray[]){
    int pairings = 0;

    for(int i=0; i<elementSize - 1; i++){
        if(theArray[i] <= theArray[i + 1])
            pairings++;
    }

    double percentPaired = (double)pairings / (elementSize - 1);

    if(percentPaired >= 0.90)
        return "Best";
    else if(percentPaired <= 0.10)
        return "Worst";
    else
        return "Average";
}

//Selection
void selectionSort(int theArray[]){
    for(int i=0; i<elementSize - 1; i++){
        int minIndex = i;

        for(int j=i + 1; j<elementSize; j++){
            if(theArray[j] < theArray[minIndex])
                minIndex = j;
        }
        int temp = theArray[minIndex];
        theArray[minIndex] = theArray[i];
        theArray[i] = temp;
    }
}

//Insertion
void insertionSort(int theArray[]){
    for(int i=1; i<elementSize; i++){
        int key = theArray[i];
        int j = i - 1;

        while(j >= 0 && theArray[j] > key){
            theArray[j + 1] = theArray[j];
            j--;
        }
        theArray[j + 1] = key;
    }
}

//Print array
void printArray(int theArray[]){
    for(int i=0; i<elementSize; i++)
        cout << theArray[i] << " ";
}

int main(){
    int array[elementSize];

    srand(time(0));

    //Fill array randomly
    for(int i=0; i<elementSize; i++)
        array[i] = rand() % 100;

    //Print original array
    cout << "Original Array:" << endl;
    printArray(array);
    cout << endl;

    //Analyze array
    string caseType = analyzeArray(array);

    cout << "\nCase Type: " << caseType << endl;

    //Adaptive selection
    if(caseType == "Best"){
        cout << "Insertion Sort selected" << endl;
        insertionSort(array);
    }
    else if(caseType == "Worst"){
        cout << "Selection Sort selected" << endl;
        selectionSort(array);
    }
    else{
        cout << "Insertion Sort selected" << endl;
        insertionSort(array);
    }

    //Print sorted array
    cout << "\nSorted Array:" << endl;
    printArray(array);

    //Return 0 success
    return 0;
}
```

### Part B:
This code will use the same type of threshold as Part A, but without the best case. This code will initialize an array size of 50 and fill it with randomly generated numbers. It will then analyze that array to see which case type classification it is.
```c++
#include <iostream>
using namespace std;

const int elementSize = 50;

//Analyzation of array
string analyzeArray(int theArray[]){
    int pairings = 0;

    for(int i=0; i<elementSize - 1; i++){
        if(theArray[i] <= theArray[i + 1]){
            pairings++;
        }
    }

    double percentPaired = (double)pairings / (elementSize - 1);

    if (percentPaired <= 0.10)
        return "Worst Case";
    else
        return "Average Case";
}

//Print array
void printArray(int theArray[]){
    for(int i=0; i<elementSize; i++)
        cout << theArray[i] << " ";
}

int main(){
    int array[elementSize];

    srand(time(0));

    //Fill array randomly
    for(int i=0; i<elementSize; i++)
        array[i] = rand() % 100;

    //Print original array
    cout << "Original Array:" << endl;
    printArray(array);
    cout << endl;

    //Classification of array
    string result = analyzeArray(array);
    cout << "\nClassification: " << result << endl;

    //Return 0 success
    return 0;
}
```

### Part C:
The way I did my threshold was I first checked on how ordered the numbers already were by comparing each number with the one next to it. If the percentage was 90% or more, that would be the best case.
If the percentage was 10% or less, that would be the worst case. Anything in between that would be the average case. My reasoning behind this was to see whether the array was sorted to some degree or if it was completely jumbled up.
My program will use this information to select between Insertion Sort for the best and average case types classifications and the Selection Sort for the worst case.
The input order affects the time complexity when sorting because Selection Sort will always take around the same amount of time, while Insertion Sort can be fast when sorted but slower the less sorted the array is.
This program improves the speed of operations by first checking the array and choosing an efficient sorting method.
