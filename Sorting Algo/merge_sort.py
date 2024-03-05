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
        sorted_array = merge_sort(array, 0, len(array)-1)
        end_time = time.time()
        execution_time = end_time - start_time
        execution_times.append(execution_time)
        sorted_arrays.append(sorted_array)
    
    return sizes, execution_times, sorted_arrays

def plot_growth_rate(sizes, execution_times):
    plt.plot(sizes, execution_times, marker='o')
    plt.title('Growth Rate of merge Sort Time Complexity')
    plt.xlabel('Size of Array (n)')
    plt.ylabel('Execution Time (s)')
    plt.grid(True)
    plt.savefig('merge_sort_growth_rate.png')

def merge(arr, start, middle, end):
    size1 = middle - start + 1
    size2 = end - middle
    
    array1 = [0] * size1
    array2 = [0] * size2

    for i in range(size1):
        array1[i] = arr[start + i]
    
    for j in range(size2):
        array2[j] = arr[middle+1+j]

    i = j = 0
    k = start
    while i < size1 and j < size2:
        if array1[i] < array2[j]:
            arr[k] = array1[i]
            i+=1
        else:
            arr[k] = array2[j]
            j+=1
        k+=1
    
    while i<size1:
        arr[k] = array1[i]
        k+=1
        i+=1
    while j<size2:
        arr[k] = array2[j]
        k+=1
        j+=1

def merge_sort(arr, start, end):
    if start < end:
        middle = (start+end) // 2
        merge_sort(arr, start, middle)
        merge_sort(arr, middle+1, end)
        merge(arr, start, middle, end)
    return arr

if __name__ == "__main__":
    sizes, execution_times, sorted_arrays = analyze_time_complexity()
    print("Sizes:", sizes)
    print("Execution Times:", execution_times)
    for size, sorted_array in zip(sizes, sorted_arrays):
        print(f"Sorted Array for size {size}:", sorted_array)
    plot_growth_rate(sizes, execution_times)