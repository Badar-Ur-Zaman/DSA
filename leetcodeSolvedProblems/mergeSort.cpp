#include <iostream>
#include <algorithm>    //for generate() method
#include <random>   //generating random numbers
#include <chrono>  // for time calculation

using namespace std;

//algorithm for dividing array
void merge(int arr[], int start, int middle, int end){
    
    size_t size1 = middle - start + 1;
    
    size_t size2 = end - middle;
    
    int a1[size1], a2[size2];
    
    for(size_t i = 0; i < size1; i++){
        a1[i] = arr[start + i];
    }
    
    for(size_t i = 0; i < size2; i++){
        a2[i] = arr[middle + 1 + i];
    }
    size_t i = 0, j = 0, k = start;
    
    while(i < size1 && j < size2){
        if(a1[i] < a2[j]){
            arr[k] = a1[i];
            k++;i++;
        }
        else if(a2[j] < a1[i]){
            arr[k] = a2[j];
            k++; j++;
        }
        else if(a1[i] == a2[j]){
            arr[k] = a1[i];
            k++;i++;
            arr[k] = a2[j];
            k++;j++;
        }
    }
    
    while(i < size1){
        arr[k] = a1[i];
        k++;i++;
    }
    while(j < size2){
        arr[k] = a2[j];
        k++;j++;
    }
    
}

//algorithm for conquering array
void mergeSort(int arr[], int start , int end){
    
    size_t middle;
    
    if(start < end){
        
        middle = (start+end)/2;
        
        mergeSort(arr, start, middle);
        
        mergeSort(arr, middle + 1, end);
        
        merge(arr, start, middle, end);
    }
}

//generating random numbers
int generateRandomNumbers(){
    static std::mt19937 generator(std::random_device{}());
    std::uniform_int_distribution<int> distribution(0, 100);
    return distribution(generator);
}

int main(){
    //size_t for greater range
    size_t size = 2000000;
    //dynamically allocating memory
    int* arr = new int[size];
    
    //Initializing Array with random integers
    generate(arr, arr+size, generateRandomNumbers);
    
    cout << "Size of arrays: " << size <<endl;
    
    //Calculating time for mergeSort
    auto startMerge = chrono::high_resolution_clock::now(); //Start recording
    mergeSort(arr, 0, size-1);
    auto stopMerge = chrono::high_resolution_clock::now(); //stop recording
    auto durationMerge = chrono::duration_cast<chrono::milliseconds>(stopMerge - startMerge); //counting duration
    
    cout << "Time by mergeSort: " << durationMerge.count() << " milliseconds" <<endl;
    
    delete[] arr; //Free memory
}