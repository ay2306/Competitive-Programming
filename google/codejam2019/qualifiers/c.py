import math
def gcd(a,b): 
    if(b==0): 
        return a 
    else: 
        return gcd(b,a%b) 
def solve(t):
    arr = [int(e) for e in input().split()]
    arr1 = []
    arr2 = []
    for i in range(len(arr)):
        if arr[i] != arr[i-1]:
            if i-2 >= 0:
                arr1 = arr[0:i-1]
            arr2 = arr[i-1:]
            break  
    el2 = []
    el1 = []
    tmp = arr2[0]/gcd(arr2[0],arr2[1])
    el2.append(tmp)
    for i in arr2:
        el2.append(i/el2[len(el2)-1])
    if len(arr1) > 0:
        el1.append(arr1[(len(arr1)-1)]/el2[0])
        i = len(arr)-2
        while i >= 0:
            el1.append(arr1[i]/el1[len(el1)-1])
            i = i-1
        el1 = el1[::-1]
    el = []
    for i in el1:
        el.append(i)
    for i in el2:
        el.append(i)
    d_el = []
    for i in el:
        if i in d_el:
            continue
        else:
            d_el.append(i)
    d_el.sort()
    dic = {}
    j = 0
    for i in d_el:
        dic[i] = chr(ord('A') + j)
        j = j+1
    s = ""
    for i in el:
        s = s+dic[i]
    print("Case #"+str(t)+": "+s)
t = int(input())
for i in range(t):
    arr = input()
    solve(i+1)