# Activity 1 Arrays

All questions will be addressed in the [YouTube video](https://youtu.be/cZaOcsu42F4). Please let me know if there's something missing or should be formatted differently since this is the first activity.

## Code in Video

```c++
#include <iostream>
using namespace std;

int main(){
    int elementSize = 100;
    int array[elementSize];

    //Output size of array element in memory
    cout << "Size of one element: " << sizeof(array) / elementSize << " bytes" << endl;
                                     //sizeof(array[0])

    //Output addresses of array in memory
    cout << "Address of array: " << array << endl;
    cout << "Address of element 1: " << &array[0] << endl;
    cout << "Address of element 2: " << &array[1] << endl;
    cout << "Address of element 3: " << &array[2] << endl;

    //Return 0 success
    return 0;
```
