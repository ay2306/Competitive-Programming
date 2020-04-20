from sys import stdin,stdout
mod = 10**9 + 7
inv = pow(6,mod-2,mod)
def cuberoot(x):
    return int(pow(x,1./3.))%mod
def squareroot(x):
    return int(pow(x,1./2.))%mod
def SumSquare(n):
    if n <= 0:
        return 0
    return (int((n*(n+1)*(2*n+1)))//6)%mod

def solve():
    # n = int(input())
    n = int(stdin.readline())
    cb = cuberoot(n)
    sq = squareroot(n)
    if (cb+1)**3 <= n:
        cb+=1
    if (sq+1)**2 <= n:
        sq+=1
    processed = {}
    # gtcls = greater than cuberoot less than squareroot 
    gtcls = []
    ans = 0
    i = 1
    while True:
        i+=1
        if i > cb:
            break
        if(i in processed or i == 0):
            continue
        power = i*i
        while True:
            if(power > n):
                break
            multiples = (n//power)%mod
            contribution = (multiples*power)%mod
            ans = (ans + contribution)%mod
            # print("POWER =",power,"Contribution =",contribution)
            processed[power] = 1
            if power > cb and power <= sq:
                gtcls.append(power)
            power *= i
    # print(ans)
    # Now we need to processed majorily all perfect powers except
    # those x^k whose x >= cuberoot. so least number for any such x is x^2
    # now consider x >= cuberoot (it mayalso), n/(x^2) is the count
    # Here things get interesting
    # consider this 
    # (n/x^2), (n/(x+1)^2), (n/(x+2)^2) can be same value as it is integer division
    # therefore
    # (n/x^2)*x^2 + (n/(x+1)^2) + ... = (n/x^2)(x^2 + (x+1)^2 + ...)
    # let n/(START)^2 = A and n/(END)^2 = A
    # now we know for n/(x^2) = 1, x^ at max can be sqrt(n) and at min be sqrt(n/2)-1
    # init_start = sqrt(n/2)+1 and sqrt(n)
    # next_start = sqrt(n/3)+1 and sqrt(n/2)
    # ans basically sqrt(n/(val+1))+1 and sqrt(n/val)
    # val*((start)^2 + (start+1)^2 + ... + (end)^2)
    # consider f(x) = sum of squares of first x natural numbers
    # val*(f(end)-f(start-1));
    # Now x >= cbroot, x^2 = n/A >= n^(2/3)
    # therefore A is at max n^(1/3)
    # print("cb = ",cb)
    i = 0
    while True:
        i+=1
        if(i*i*i > n):
            break
        if i == 0:
            continue
        start = squareroot(n/(i+1))+1
        end = squareroot(n/i)
        # print("i = ",i,"start = ",start,"end = ",end,"ssq = ",n/(i+1),"esq = ",n/i)
        if start <= cb:
            start = cb+1
        if start <= end:
            ans = (ans + ((SumSquare(end) - SumSquare(start-1) + mod)%mod*i))
    # print(ans)
    # Now we have included all the squares.
    # But consider N = 1e18 and we went to 1e8 and 1e16 as well
    # they are added twice, so
    # we can just not include them above and let them be here
    # but lets say there was a number which was prime^3 it won't be counted as though it okay but not square
    # so will use saved onces
    for i in gtcls:
        data = i*i
        factor = i
        ans = (ans-((n//data)*data+mod))%mod
    # print(ans)
    ans = (ans + n)%mod
    # print(ans)
    stdout.write(str(ans))
    stdout.write('\n')

# t = int(input())
t = int(stdin.readline())
for i in range(t):
    solve()