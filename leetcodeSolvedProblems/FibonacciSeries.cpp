#include <iostream>
#include<time.h>
#include <chrono>
using namespace std;

long cal_recursiveFibonacciElement(int n){
    //Base case : if user input negative value
    if(n <= 0){
        return 0;
    }//If n is 1 so just print 1
    else if(n  == 1){
        return 1;
    }else if(n > 1){
        // adding previous two values
        return cal_recursiveFibonacciElement(n-1) + cal_recursiveFibonacciElement(n-2);
    }
}

void cal_iterativeFibonacci(int n){
    int a = 0, b = 1;
    cout << a << " " << b << " ";
    for(int j = 2; j < n; j++){
        //Adding previous values and simply printing the last one
        long temp = a+b;
        a = b;
        b = temp;
        cout << b << " ";
        
    }
}

int main(){
    int n = 10;
    auto startRec = std::chrono::high_resolution_clock::now();//Start Recording time
    
    for(int i = 0; i < n; i++){
        cout << cal_recursiveFibonacciElement(i) << " ";
    }
    auto endRec = std::chrono::high_resolution_clock::now();//end Recording time
    cout << endl;
    auto durationRec = std::chrono::duration_cast<std::chrono::microseconds>(endRec - startRec);
    //Printing the time taken by recursive function
    cout << durationRec.count() << " ms";
    cout << endl;

    auto start = std::chrono::high_resolution_clock::now();//Start Recording time
    
    cal_iterativeFibonacci(n);
    
    auto end = std::chrono::high_resolution_clock::now();//end Recording time
    cout << endl;
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    //Printing the time taken by iterative function
    cout <<  duration.count() << " ms"; 

}
