import random

def binary_search(arr, element):
    low = 0
    high = len(arr)
    while low <= high:
        mid = low + (high - low)/2
        if arr[mid] == element:
            return mid
        if arr[mid] > element:
            high = mid - 1
        if arr[mid] < element:
            low = mid + 1
    return -1
arr_length = random.randint(50,5000)
arr = []
i = 0
lowerLimit = 10
maxLimit = 50
while i < arr_length:
    arr.append(random.randint(lowerLimit,maxLimit))
    lowerLimit = arr[i]
    maxLimit = lowerLimit + 50
    i = i + 1
print(binary_search(arr,arr[45]))