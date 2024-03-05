#include <iostream>
#include <vector>
using namespace std;

class stack_Arr {
    int topElement = -1;
    int stackSize;
    vector <int> Arr;
    public:
    stack_Arr(int Size){
        Arr.resize(Size);
        stackSize = Size;
    }
    bool isEmpty() {
    return (topElement == -1);
    }
    
    bool isFull() {
        return (topElement == stackSize - 1);
    }
    void push(int element){
        if(isFull()){
            cout << "Stack Full" << endl;
        }else{
            topElement++;
            Arr[topElement] = element;
        }
    }
    void pop(){
        if(!isEmpty()){
            topElement--;
        }else{
            cout << "Stack is Empty" << endl;
        }
    }
    int top(){
        if(!isEmpty()){
            return Arr[topElement];
        }
    }
};

int main()
{
    stack_Arr myStack(5);
    
    myStack.push(3);
    myStack.push(5);
    myStack.push(1);
    
    myStack.pop();
    
    cout << myStack.top() << endl;
    
    myStack.push(26);
    
    cout << "Stack Size: " << myStack.isEmpty() <<endl;
    
    if(myStack.isFull()){
        cout << "Size of Stack: " << myStack.stackSize << endl;
    }
    

    return 0;
}
