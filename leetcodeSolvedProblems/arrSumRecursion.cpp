//Print array sum by using recursion
#include <iostream>
using namespace std;

//For array sum we use the following function

int calSum(int arr[],int n){
    if(n == 0){
        return 0;
    }
    return arr[0] + calSum(arr+1, n-1);
    
}

//Whether you enter even or odd
//It will calculate sum of only odd numbers

int calSum(int n){
    if(n < 0){
        return -1;
    }
    else if(n == 0){
        return 0;
    }
    else if(n%2 == 1 && n >1){
        return n + calSum(n-2);
    }else if(n%2==0){
        return calSum(n-1);
    }
}

int main() {
    int arr[] = {23,4,5,6,67};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout << calSum(arr, size);

    cout << calSum(8);
    return 0;
}
