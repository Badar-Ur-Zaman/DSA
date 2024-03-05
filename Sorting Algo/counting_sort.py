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
        sorted_array = count_sort(array)
        end_time = time.time()
        execution_time = end_time - start_time
        execution_times.append(execution_time)
        sorted_arrays.append(sorted_array)
    
    return sizes, execution_times, sorted_arrays

def plot_growth_rate(sizes, execution_times):
    plt.plot(sizes, execution_times, marker='o')
    plt.title('Growth Rate of Count Sort Time Complexity')
    plt.xlabel('Size of Array (n)')
    plt.ylabel('Execution Time (s)')
    plt.grid(True)
    plt.savefig('count_sort_growth_rate.png')

def count_sort(array):
    maxVal = max(array)

    count_array = [0] * (maxVal + 1)

    for num in array:
        count_array[num] += 1
    
    for i in range(1, len(count_array)):
        count_array[i] += count_array[i-1]
    
    result = [0] * len(array)

    for i in range(len(array)):
        result[count_array[array[i]]-1] = array[i]
        count_array[array[i]] -= 1
    
    return result

if __name__ == "__main__":
    sizes, execution_times, sorted_arrays = analyze_time_complexity()
    print("Sizes:", sizes)
    print("Execution Times:", execution_times)
    for size, sorted_array in zip(sizes, sorted_arrays):
        print(f"Sorted Array for size {size}:", sorted_array)
    plot_growth_rate(sizes, execution_times)