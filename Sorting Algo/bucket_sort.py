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
        sorted_array = bucket_sort(array)
        end_time = time.time()
        execution_time = end_time - start_time
        execution_times.append(execution_time)
        sorted_arrays.append(sorted_array)
    
    return sizes, execution_times, sorted_arrays

def plot_growth_rate(sizes, execution_times):
    plt.plot(sizes, execution_times, marker='o')
    plt.title('Growth Rate of Bucket Sort Time Complexity')
    plt.xlabel('Size of Array (n)')
    plt.ylabel('Execution Time (s)')
    plt.grid(True)
    plt.savefig('bucket_sort_growth_rate.png')

def bubble_sort(array):
    for i in range(len(array)):
        swapped = False
        for j in range(len(array)-i-1):
            if array[j] > array[j+1]:
                array[j], array[j+1] = array[j+1], array[j]
                swapped = True
        if swapped == False:
            break
    return array

def bucket_sort(arr):
    min_val = min(arr)
    max_val = max(arr)
    
    slot_num = max_val - min_val + 1
    
    array = [[] for _ in range(slot_num)]
    
    for j in arr:
        index = j - min_val
        array[index].append(j)

    for i in range(slot_num):
        array[i] = bubble_sort(array[i])

    k = 0
    for i in range(slot_num):
        for j in range(len(array[i])):
            arr[k] = array[i][j]
            k += 1
    return arr

if __name__ == "__main__":
    sizes, execution_times, sorted_arrays = analyze_time_complexity()
    print("Sizes:", sizes)
    print("Execution Times:", execution_times)
    for size, sorted_array in zip(sizes, sorted_arrays):
        print(f"Sorted Array for size {size}:", sorted_array)
    plot_growth_rate(sizes, execution_times)