def solve():
    n = int(input())
    arr = []
    ans = []
    for i in range(n):
        op = input().split(' ');
        arr.append(op)
        ans.append(op)
    ans = ans[::-1]
    ans[0][0] = 'Begin'
    print(ans)
    print(arr)
    i = n-1
    j = 1
    while j < n:
        print(str(arr[i]) + ' i = ' + str(i) + ' j = ' + str(j))
        if arr[i][0] == 'Left':
            ans[j][0] = 'Right'
        else:
            ans[j][0] = 'Left'
        j+=1
        i-=1
    for k in ans:
        print (k)
t = int(input())
for p in range(t):
    solve()