for _ in range (int(input())):
    j=input() 
    s=input()
    j=list(j)
    s = [(e in j) for e in list(s)]
    print(sum(s))