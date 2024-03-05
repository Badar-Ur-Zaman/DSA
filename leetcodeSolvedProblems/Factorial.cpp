#include <iostream>
#include <chrono>
using namespace std;


//Assigning long long return type for bigger values 
unsigned long long calFactorialRec(int n){
    if (n < 0) {
        return -1;
    } else if (n == 0 || n == 1) { // Change the condition here
        return 1;
    } else if (n > 1) {
        return n * calFactorialRec(n - 1);
    }
}

unsigned long long calFactorialIter(int n){
    unsigned long long fact = 1;
    for (int i = n; i > 0; i--){
        fact *= i;
    }
    return fact;
}

int main(){
    int input = 15;
    auto startRec = std::chrono::high_resolution_clock::now();
    cout << "Recursive factorial of " << input << ": " << calFactorialRec(input) << " ";
    auto endRec = std::chrono::high_resolution_clock::now();
    //Printing the time taken by recursive function
    cout << endl;
    auto durationRec = std::chrono::duration_cast<std::chrono::microseconds>(endRec - startRec);
    cout << "Time taken by recursive method: " <<durationRec.count() << " ms";
    
    auto start = std::chrono::high_resolution_clock::now();//Start Recording time
    cout << endl;

    cout << "Iterative factorial of " << input << ": " << calFactorialIter(input);
    auto end = std::chrono::high_resolution_clock::now();//end Recording time
    cout << endl;
    
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    //Printing the time taken by iterative function
    cout << "Time taken by iterative method: " << duration.count() << " ms"; 
}
