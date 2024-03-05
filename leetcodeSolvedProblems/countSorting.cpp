#include <iostream>
#include <chrono>
#include <random>
#include <algorithm>

using namespace std;

void countSort(int arr[], size_t n) {
    if (n <= 1) {
        return;
    }

    int k = arr[0];

    // Max value in the array
    for (size_t i = 1; i < n; i++) {
        if (arr[i] > k) {
            k = arr[i];
        }
    }

    // To store counts
    int* count = new int[k + 1]();
    for (size_t i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    // Updating original Array
    size_t j = 0;
    for (int i = 0; i <= k; i++) {
        while (count[i]-- > 0) {
            arr[j++] = i;
        }
    }

    // Free the dynamically allocated count array
    delete[] count;
}

// Generating random numbers within a range
int generateRandomNumber() {
    static std::mt19937 generator(std::random_device{}());
    std::uniform_int_distribution<int> distribution(0, 100);
    return distribution(generator);
}

int main() {
    size_t size = 10000000;
    int* Arr = new int[size];
    int* Arr1 = new int[size];

    generate(Arr, Arr + size, generateRandomNumber);
    generate(Arr1, Arr1 + size, generateRandomNumber);
    
    cout << "Size of two Arrays: " << size <<endl;
    
    auto startCount = chrono::high_resolution_clock::now();
    countSort(Arr, size);
    auto stopCount = chrono::high_resolution_clock::now();

    auto durationCount = chrono::duration_cast<chrono::milliseconds>(stopCount - startCount);

    cout << "Duration for count sort: " << durationCount.count() << " milliseconds" << endl;

    delete[] Arr; // Free the dynamically allocated array
    
    //Calculating duration for sort()
    
    auto startDefault = chrono::high_resolution_clock::now();
    sort(Arr1, Arr1 + size);
    auto stopDefault = chrono::high_resolution_clock::now();
    
    auto durationDefault = chrono::duration_cast<chrono::milliseconds>(stopDefault - startDefault);
    
    cout << "Duration for default sorting algorithm: " << durationDefault.count() << " milliseconds" <<endl;
    
    return 0;
}

