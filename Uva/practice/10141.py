# import sys
# sys.stdin = open('input.txt','r')
# sys.stdout = open('output.txt','w')
seq = 1
while(1):
    inp = input().split()
    n = int(inp[0])
    p = int(inp[1])
    if n == 0 and p == 0:
        break
    if seq > 1:
        print('')
    for i in range(n):
        a = input()
    minCost = 1000000000000000
    cmpAns = ''
    featMatched = 0
    for k in range(p):
        compName = input()
        inp = input().split()
        cost = float(inp[0])
        feat = int(inp[1])
        if feat == featMatched:
            if minCost > cost:
                minCost = cost
                cmpAns = compName
        if feat > featMatched:
            minCost = cost
            cmpAns = compName
            featMatched = feat
        for l in range(feat):
            lalala = input()
    print('RFP #' + str(seq))
    seq = seq+1
    print(cmpAns)