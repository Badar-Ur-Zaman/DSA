#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class Stack_linkedList {
private:
    Node* head;
    int stackSize;

public:
    Stack_linkedList() {
        head = nullptr;
        stackSize = 0;
    }

    bool isEmpty() {
        return (stackSize == 0);
    }

    void push(int element) {
        Node* newNode = new Node(element);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            head = newNode;
            newNode->next = temp;
        }
        stackSize++;
    }
    void pop(){
        if(!isEmpty()){
            Node * temp = head;
            head = head->next;
            delete temp;
            stackSize--;
        }
    }
    int top(){
        if(!isEmpty()){
            return head->data;
        }
    }
    int size(){
        return stackSize;
    }
};

int main() {
    Stack_linkedList stack;

    stack.push(1);
    stack.push(2);
    stack.push(3);
    cout << "Stack Size: " << stack.size() << endl;
    
    cout << "Stack is empty: " << (stack.isEmpty() ? "true" : "false") << endl;
    stack.pop();
    cout << "Stack top: " << stack.top() << endl;
    cout << "Stack Size: " << stack.size() << endl;
    stack.pop();
    cout << "Stack top: " << stack.top() << endl;
    cout << "Stack Size: " << stack.size() << endl;

    return 0;
}



