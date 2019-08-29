# import sys
# sys.stdin = open('input.txt','r')
# sys.stdout = open('output.txt','w')
cas = 0
while(True):
    inp = ''
    try:
        n = int(input())
        if cas > 0:
            print('')
        else:
            cas = 10
        names = input()
        checker = {}
        for name in names.split():
            checker[name] = 0
        for t in range(n):
            inp = input()
            inp = inp.split()
            name = inp[0]
            mon = int(inp[1])
            q = int(inp[2])
            other_names = inp[3:]
            if q == 0:
                continue
            checker[name] = int(checker[name]) - (int(mon/q)*q)
            for tempName in other_names:
                checker[tempName] = int(checker[tempName])+ int(mon/q)
        # print(names)
        for i in names.split():
            # print (i)
            print(i + ' ' + str(checker[i]))
    except EOFError:
        break
