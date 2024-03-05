import random
import time
import matplotlib.pyplot as plt

def analyze_time_complexity():
    sizes = [10, 20, 30, 40, 50]
    execution_times = []
    sorted_arrays = []

    for size in sizes:
        array = [random.randint(1, 1000) for _ in range(size)]
        start_time = time.time()
        sorted_array = quick_sort(array, 0, len(array)-1)
        end_time = time.time()
        execution_time = end_time - start_time
        execution_times.append(execution_time)
        sorted_arrays.append(sorted_array)
    
    return sizes, execution_times, sorted_arrays

def plot_growth_rate(sizes, execution_times):
    plt.plot(sizes, execution_times, marker='o')
    plt.title('Growth Rate of Quick Sort Time Complexity')
    plt.xlabel('Size of Array (n)')
    plt.ylabel('Execution Time (s)')
    plt.grid(True)
    plt.savefig('quick_sort_growth_rate.png')

def partition(arr, l, h):
    pivot = arr[l]
    i = l
    j = h

    while i<j:
        while i < h and arr[i] <= pivot:
            i += 1
        while j > l and arr[j] > pivot:
            j -= 1
        if i < j:
            arr[i], arr[j] = arr[j], arr[i]
    arr[l], arr[j] = arr[j], arr[l]
    return j

def quick_sort(arr,l,h):
    if l < h:
        j = partition(arr, l, h)
        quick_sort(arr,l,j-1)
        quick_sort(arr,j+1,h)
    return arr

if __name__ == "__main__":
    sizes, execution_times, sorted_arrays = analyze_time_complexity()
    print("Sizes:", sizes)
    print("Execution Times:", execution_times)
    for size, sorted_array in zip(sizes, sorted_arrays):
        print(f"Sorted Array for size {size}:", sorted_array)
    plot_growth_rate(sizes, execution_times)