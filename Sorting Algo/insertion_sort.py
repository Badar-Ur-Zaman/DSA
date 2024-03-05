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
        sorted_array = insertion_sort(array)
        end_time = time.time()
        execution_time = end_time - start_time
        execution_times.append(execution_time)
        sorted_arrays.append(sorted_array)

    return sizes, execution_times, sorted_arrays

def insertion_sort(array):
    for i in range(1, len(array)):
        j = i
        while j >= 1 and array[j] < array[j-1]:
            array[j] , array[j-1] = array[j-1] , array[j]
            j = j - 1
    return array

def plot_growth_rate(sizes, execution_times):
    plt.plot(sizes, execution_times, marker='o')
    plt.title('Insertion Sort Time Complexity')
    plt.xlabel('Array Size (n)')
    plt.ylabel('Time (s)')
    plt.grid(True)
    plt.show()

if __name__ == "__main__":
    sizes, execution_times, sorted_arrays = analyze_time_complexity()
    print("Sizes:", sizes)
    print("Execution Times:", execution_times)
    for size, sorted_array in zip(sizes, sorted_arrays):
        print(f"Sorted Array for size {size}:", sorted_array)
    plot_growth_rate(sizes, execution_times)
