# import sys
# sys.stdout = open('output.txt','w')
# sys.stdin = open('input.txt','r')
t = int(input())
for testCases in range(t):
    inp = input()
    m = 0
    f = 0
    sp = 0
    for i in inp:
        if i == 'M':
            m = m+1
        if i == 'F':
            f = f+1
        if i == ' ':
            sp = sp+1
    if sp == 0 or m != f:
        print("NO LOOP")
    else:
        print("LOOP")