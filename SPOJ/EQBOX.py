import math
def solve():
    arr = [int(e) for e in input().split()]
    if arr[0] < arr[1]:
        arr[0],arr[1] = arr[1],arr[0]
    if arr[2] < arr[3]:
        arr[2],arr[3] = arr[3],arr[2]
    k = (arr[2]*arr[2])+(arr[3]*arr[3])-(arr[1]*arr[1])-(arr[0]*arr[0])
    k = k/(2*arr[1]*arr[0])
    if k>= 0 and k <= 1:
        print("Box cannot be dropped.")
    else:
        print("Escape is possible.")

t = int(input())
for i in range(t):
    solve()