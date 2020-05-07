def solution(x,y):
    x.sort()
    y.sort()
    print('x = ',x)
    print('y = ',y)
    if len(x) > len(y):
        x,y=y,x
    for i in range(len(x)):
        if x[i] != y[i]:
            return y[i]
    return y[len(y)-1]
print(solution([13, 5, 6, 2, 5],[5, 2, 5, 13]))
print(solution([14, 27, 1, 4, 2, 50, 3, 1],[2, 4, -4, 3, 1, 1, 14, 27, 50]))