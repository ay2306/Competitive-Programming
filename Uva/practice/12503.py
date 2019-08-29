t = int(input())
for case in range(t):
    pos = 0
    n = int(input())
    arr = []
    for k in range(n):
        inp = input()
        if inp == 'LEFT':
            pos = pos-1
        elif inp == 'RIGHT':
            pos = pos+1
        else:
            inp = arr[int(inp.split()[2])-1]
            if inp == 'LEFT':
                pos = pos-1
            elif inp == 'RIGHT':
                pos = pos+1
        arr.append(inp)
    print(pos)
