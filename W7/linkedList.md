# Activity 7 Linked-lists

## Questions
### Question 1
The linked list is efficient for stack implementation because it allows dynamic memory allocation.
This pretty much makes memory grow dynamically to the specifications of the linked list so it won't overflow or underflow.
Arrays are fixed size so they can't do the same as linked list with dynamic memory allocation.

### Question 2
The time complexity of push() and pop() operations is O(1) because both operations can just go straight to the node and not the whole list.

### Question 3
If memory is not deallocated after pop() operation, it will cause a memory leak with the removed node occupying the memory causing your computer to run slower.

### Question 4
|  | Array | Linked List |
|---|---|---|
| Size | Fixed | Dynamic |
| Memory Allocation | Fixed | Dynamic |
| Overflow | When full | Not likely |

Arrays are a fixed size and allocates memory to what they are initialized with, whereas a linked list is more flexible in size and memory allocation, allowing for the size of memory to be just what is needed. This plays into stack overflow, where the array will overflow if there are too many, while a linked list can grow to accommodate the amount.

### Part 4
```c++
void Stack::push(int value){
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}
```
### Part 5
```c++
void Stack::pop(){
    if(isEmpty()){
        cout << "Stack Underflow" << endl;
        return;
    }
    Node* temp = top;
    top = top->next;
    delete temp;
}
```
### Part 6
```c++
int Stack::peek(){
    if(isEmpty()){
        cout << "Stack is empty" << endl;
        return -1;
    }
    return top->data;
}
```
### Part 7
```c++
bool Stack::isEmpty(){
    return top == nullptr;
}
```
### Part 8
```c++
void Stack::display(){
    if(isEmpty()){
        cout << "Stack is empty" << endl;
        return;
    }
    Node* current = top;

    cout << "Stack elements:" << endl;
    while(current != nullptr){
        cout << current->data << endl;
        current = current->next;
    }
    cout << endl;
}
```
### Part 9
```c++
int main(){
    Stack s;

    //Push values into linked list
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    //Print linked list
    s.display();

    //Pop current top variable
    s.pop();

    //Print top element
    cout << "Top element: " << s.peek() << endl;
    cout << endl;

    //Print linked list 2
    s.display();

    //Pop top variable until underflow
    s.pop();
    s.pop();
    s.pop();
    s.pop();

    //Return 0 success
    return 0;
}
```
### Part 10
Using pop() until it's an empty stack, we can check for stack underflow with isEmpty() inside of void Stack::pop() and output "Stack Underflow."

Main
```c++
s.pop();
```

void Stack::pop()
```c++
    if(isEmpty()){
        cout << "Stack Underflow" << endl;
        return;
    }
```
## Code all together
```c++
#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

class Stack{
private:
    Node* top;
public:
    Stack();

    void push(int value);
    void pop();
    int peek();
    bool isEmpty();
    void display();
};

Stack::Stack(){
    top = nullptr;
}

void Stack::push(int value){
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

void Stack::pop(){
    if(isEmpty()){
        cout << "Stack Underflow" << endl;
        return;
    }
    Node* temp = top;
    top = top->next;
    delete temp;
}

int Stack::peek(){
    if(isEmpty()){
        cout << "Stack is empty" << endl;
        return -1;
    }
    return top->data;
}

bool Stack::isEmpty(){
    return top == nullptr;
}

void Stack::display(){
    if(isEmpty()){
        cout << "Stack is empty" << endl;
        return;
    }
    Node* current = top;

    cout << "Stack elements:" << endl;
    while(current != nullptr){
        cout << current->data << endl;
        current = current->next;
    }
    cout << endl;
}

int main(){
    Stack s;

    //Push values into linked list
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    //Print linked list
    s.display();

    //Pop current top variable
    s.pop();

    //Print top element
    cout << "Top element: " << s.peek() << endl;
    cout << endl;

    //Print linked list 2
    s.display();

    //Pop top variable until underflow
    s.pop();
    s.pop();
    s.pop();
    s.pop();

    //Return 0 success
    return 0;
}
```
