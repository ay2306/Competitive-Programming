def solve():
    #General input section
    inp = input()
    # n = int(inp.split(' ')[0])
    # k = int(inp.split(' ')[1])
    # x = int(inp.split(' ')[2])
    n,k,x = map(int,inp.split(' '))
    inp = input()
    rng = 1000000000
    mn = rng + 2
    arr = list(map(int,inp.split(' ')))
    #Just sorting the array
    arr.sort()
    # for e in inp.split(' '):
    #     arr.append(int(e))
    #General input section END
    #Step1: Find minimum of the array
    mn = arr[0]
    #Step2: Find the maximum term for p array in question
    max_term = mn + x
    if max_term > rng:
        max_term = rng
    #Step 3:
    #I have to explain what I did after this
    #Let's say max_term = 50, n = 10, k = 3
    #arr = 11,26,58
    #then I tried 
    #to find sum of digits from 44-50
    #which can be written as (1+2+3+..+50)-(1+2+3+..+43)
    
    max_sum = int(((max_term)*(max_term+1))/2)
    min_term = (max_term-(n-k))
    min_sum = int(((min_term)*(min_term+1))/2)
    sm = max_sum-min_sum
    #Setting last included term to 44, as till now it was 43
    #as of example i gave
    min_term += 1
    i = k-1
    while i >= 0:
        #If a given number is greater,equal to min_term
        #this means, it is already added
        #so decrease min_terms to a level it is not included
        if arr[i] >= min_term:
            min_term -= 1
            sm += min_term
        else:
            sm += arr[i]
        i -= 1
    # print (mn)
    print (int(sm))

t = int(input())
for i in range(t):
    solve()