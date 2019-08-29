import random
import math

def min(a,b):
    if(a>b):
        return b
    else:
        return a

def jump_search(arr, element):
    arr_len = len(arr)
    step = int(math.floor(math.sqrt(arr_len)))
    prev = 0
    while arr[min(step,arr_len)] < element:
        prev = step
        step = step + int(math.floor(math.sqrt(arr_len)))
        if prev >= arr_len:
            return -1
    while arr[prev]<element:
        prev = prev + 1
        if prev == min(step,arr_len):
            return -1
    if arr[prev] == element:
        return prev
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
print(jump_search(arr,arr[random.randint(0,arr_length)]))