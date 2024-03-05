#include <iostream>
#include <stack>
using namespace std;


int main() {
    const int maxSize = 100;
    stack <char> stringStack;
    bool flag = true;
    
    string myStringInput;
    
    getline(cin, myStringInput);
    
    for(int i = 0; i < myStringInput.length(); i++){
        char inputChar = myStringInput[i];
        
        if(inputChar == '(' || inputChar == '{' || inputChar == '['){
            stringStack.push(inputChar);
        }else if(inputChar == ')' || inputChar == '}' || inputChar == ']'){
                if(stringStack.empty()){
                    flag = false;
                    break;
                }
                else if((inputChar == ')' && stringStack.top() == '(')
                        || (inputChar == '}' && stringStack.top() == '{')
                        || (inputChar == ']' && stringStack.top() == '[')){
                            stringStack.pop();
                }
                else{
                    flag = false;
                }
        }
    }
    if(flag){
        cout << "This expression is correct";
    }else{
        cout << "This expression is not correct";
    }
}
