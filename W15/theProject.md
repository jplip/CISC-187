# Project

## Tasks
### Task 1
This will compare the two vectors of players from basketball and football to see if there are any players in both sports.
This is done through the function, bothSports, which will checck if the player's name is in both sports.
The runtime is $O(N + M)$ as it inserts basketball players into the set and then checks them against the football players.
```
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

struct Player{
    string firstName;
    string lastName;
    string team;
};

vector<string> bothSports(const vector<Player>& basketball_players, const vector<Player>& football_players){
    unordered_set<string> bbSet;
    vector<string> result;

    for(const auto& player : basketball_players){
        string fullName = player.firstName + " " + player.lastName;
        bbSet.insert(fullName);
    }

    for(const auto& player : football_players){
        string fullName = player.firstName + " " + player.lastName;

        if(bbSet.find(fullName) != bbSet.end())
            result.push_back(fullName);
    }
    return result;
}

int main(){
    //Vector of basketball players
    vector<Player> basketball_players = {
        {"Jill", "Huang", "Gators"},
        {"Janko", "Barton", "Sharks"},
        {"Wanda", "Vakulskas", "Sharks"},
        {"Jill", "Moloney", "Gators"},
        {"Luuk", "Watkins", "Gators"}
    };

    //Vector of football players
    vector<Player> football_players = {
        {"Hanzla", "Radosti", "32ers"},
        {"Tina", "Watkins", "Barleycorns"},
        {"Alex", "Patel", "32ers"},
        {"Jill", "Huang", "Barleycorns"},
        {"Wanda", "Vakulskas", "Barleycorns"}
    };

    //Duplicate person so multiple sports call function
    vector<string> duplicate = bothSports(basketball_players, football_players);

    //Print
    cout << "Players:" << endl;
    for(const auto& name : duplicate)
        cout << name << endl;

    //Return 0 success
    return 0;
}
```
Output
```
Players in both sports:
Jill Huang
Wanda Vakulskas

Process finished with exit code 0
```

### Task 2
This will use the function, numberFinder, to find the number that is missing inside of the vector example from $0, 1, 2, ..., N.
The runtime is $O(N)$ because they pass in through the vector one at a time.
```
#include <iostream>
#include <vector>
using namespace std;

int numberFinder(const vector<int>& ex){
    int n = ex.size();
    int inVectorShouldBeSum = n * (n + 1) / 2;
    int inVectorSum = 0;

    for(int value : ex)
        inVectorSum += value;

    int result = inVectorShouldBeSum - inVectorSum;
    return result;
}

int main(){
    //Vector missing 4
    vector<int> ex1 = {2, 3, 0, 6, 1, 5};

    //Vector missing 1
    vector<int> ex2 = {8, 2, 3, 9, 4, 7, 5, 0, 6};

    //Print
    cout << "Missing number for example 1: " << numberFinder(ex1) << endl;
    cout << "Missing number for example 2: " << numberFinder(ex2) << endl;

    //Return 0 success
    return 0;
}
```
Output
```
Missing number for example 1: 4
Missing number for example 2: 1

Process finished with exit code 0
```

### Task 3
This will use the function, stockMaxxing, to find the maximum profit when buying and selling stock during a time period of a week in order to predict prices over the course of time.
It will analyze the prices per day to determine the max profit.
The runtime is $O(N)$ because it passes through the vector once.
```
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int stockMaxxing(const vector<int>& price){
    int n = price.size();

    int minPrice = price[0];
    int maxProfit = 0;

    for(int i=1; i<n; i++){
        int currentProfit = price[i] - minPrice;

        maxProfit = max(maxProfit, currentProfit);
        minPrice = min(minPrice, price[i]);
    }
    return maxProfit;
}

int main(){
    //Vector with seven prices for 1 week
    vector<int> price = {10, 7, 5, 8, 11, 2, 6};

    //Print
    cout << "Max Profit: $" << stockMaxxing(price) << endl;

    //Return 0 success
    return 0;
}
```
Output
```
Max Profit: $6

Process finished with exit code 0
```

### Task 4
This will use the function, productHighest, to find the highest product of two numbers with either positives or negatives since we have at least two of each type.
The runtime is $O(N)$ because it goes through the vector once.
```
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int productHighest(const vector<int>& numbers){
    int pos1 = 0;
    int pos2 = 0;
    int neg1 = 0;
    int neg2 = 0;

    for(int value : numbers){
        if(value > pos1){
            pos2 = pos1;
            pos1 = value;
        }
        else if(value > pos2)
            pos2 = value;

        if(value < neg1){
            neg2 = neg1;
            neg1 = value;
        }
        else if(value < neg2)
            neg2 = value;
    }

    int posProduct = pos1 * pos2;
    int negProduct = neg1 * neg2;
    int result = max(posProduct, negProduct);

    return result;
}

int main(){
    //Vector with random numbers that also contains negatives
    vector<int> numbers = {5, -10, -6, 9, 4};

    //Print
    cout << "Highest product: " << productHighest(numbers) << endl;

    //Return 0 success
    return 0;
}
```
Output
```
Highest product: 60

Process finished with exit code 0
```

### Task 5
This will sort the temperatures of the human patients from a range of 97.0 to 99.0 degrees Fahrenheit.
The runtime is $O(N)$ because it will go through the vector once with also a fixed second loop of a vector size of 21.
This means the temperature range will never change and the runtime will grow linearly.
```
#include <iostream>
#include <vector>
using namespace std;

vector<double> sortTemperatures(const vector<double>& temperatures){
    const int SIZE = 21;
    vector<int> count(SIZE, 0);

    for(double value : temperatures){
        int index = static_cast<int>((value - 97.0) * 10 + 0.5);
        count[index]++;
    }

    vector<double> sortedTemperatures;
    for(int i=0; i<SIZE; i++){
        double theTemperature = 97.0 + (i * 0.1);

        while(count[i] > 0){
            sortedTemperatures.push_back(theTemperature);
            count[i]--;
        }
    }
    return sortedTemperatures;
}

int main(){
    //Vector with patient temperatures
    vector<double> temperatures = {98.6, 98.0, 97.1, 99.0, 98.9, 97.8, 98.5, 98.2, 98.0, 97.1};

    //Call function for sorter temperatures
    vector<double> sorted = sortTemperatures(temperatures);

    //Print
    cout << "Sorted temperatures:" << endl;
    for (double value : sorted)
        cout << value << " ";
    cout << endl;

    //Return 0 success
    return 0;
}
```
Output
```
Sorted temperatures:
97.1 97.1 97.8 98 98 98.2 98.5 98.6 98.9 99

Process finished with exit code 0
```

### Task 6
This will use the function, LCS, to find the longest consecutive sequence within the vector.
The runtime is $O(N)$ because the unordered_set will allow insertions and reads in a constant time.
Each number is only checked once when finding the sequence so it will grow proportionally to the size.
```
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

int LCS(const vector<int>& ex){
    if(ex.empty()){
        return 0;
    }

    unordered_set<int> exSet(ex.begin(), ex.end());
    int longestLength = 0;

    for(int value : exSet){
        if(exSet.find(value - 1) == exSet.end()){
            int currentNumber = value;
            int currentLength = 1;

            while(exSet.find(currentNumber + 1) != exSet.end()){
                currentNumber++;
                currentLength++;
            }
            longestLength = max(longestLength, currentLength);
        }
    }
    return longestLength;
}

int main(){
    //Vectors with example numbers
    vector<int> ex1 = {10, 5, 12, 3, 55, 30, 4, 11, 2};
    vector<int> ex2 = {19, 13, 15, 12, 18, 14, 17, 11};

    //Print
    cout << "Longest consecutive sequence length is: " << LCS(ex1) << endl;
    cout << "Longest consecutive sequence length is: " << LCS(ex2) << endl;

    //Return 0 success
    return 0;
}
```
Output
```
Longest consecutive sequence length is: 4
Longest consecutive sequence length is: 5

Process finished with exit code 0
```
