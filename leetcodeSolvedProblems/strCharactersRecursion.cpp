#include <iostream>
using namespace std;

void printCharacter(string str){
    if(str.length() == 0){
        return;
    }else if(str.length() > 0){
        printCharacter(str.substr(0,str.length()-1));
        cout << str[str.length()-1] << endl;
    }
}

int main() {
    string str = "Abubaker123";
    printCharacter(str);

    return 0;
}