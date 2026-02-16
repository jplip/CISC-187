# Activity 2 Searching
## [YouTube video](https://youtu.be/O4K4biiQiU0) answering Questions 4 and 5.

# Questions

## 1. How many steps would it take to perform a linear search for the number 8 in the ordered array, [2, 4, 6, 8, 10, 12, 13]? - **1 pt**
It would take 4 steps because a linear search will check each element starting from index[0].

## 2. How many steps would binary search take for the previous example? - **1 pt**
It would take 1 step because a binary search will take the midpoint of from (0+6)/2 to get the index of 3, which is the position of the being searched for.

## 3. What is the maximum number of steps it would take to perform a binary search on an array of size 100,000? - **1 pt**
The maximum number of steps a binary search of this calibre would be 17. This is because 2^16 = 65,536 and 2^17 = 131,072 with an array size of 100,000 meaning the maxiumum is 17.

## 4. Write a C++ program that implements both linear search and binary search algorithms using an array of 100,000 elements. The program should record and report the number of steps (comparisons) performed during each search operation. In addition, analyze and justify the observed behavior by providing a theoretical explanation using Big-O notation, demonstrating why linear search exhibits $O(N)$ complexity and binary search exhibits $O(\log N)$ complexity. - **2 pts**
```c++
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
```

## 5. Write pseudocode for a randomized search algorithm that searches for a given key by randomly selecting indices __without repetition__. Use a dataset of 100,000 distinct elements, stored in a vector. Each element may be examined __at most__ once during the search. Analyze and state the best-case, average-case, and worst-case time complexities of this algorithm using Big-O notation. Then, implement the algorithm in C++, using only the following standard headers: ```<vector>``` for data storage, ```<random>``` for random index generation, and ```<iostream>``` for input and output. The implementation should track and report the number of comparisons performed during the search. Finally, compare and contrast the randomized search algorithm with linear search and binary search in terms of time complexity, data requirements (such as ordering), and practical efficiency. Discuss scenarios in which each approach may be preferred, highlighting the advantages and limitations of randomized search relative to linear and binary search. - **5 pts**



```c++
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
```
