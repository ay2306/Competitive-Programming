inp = raw_input()
# print 'pello',
# print inp,
# print ' hello'
n = int(inp.split(' ')[0])
k = int(inp.split(' ')[1])
if n==1 and k == 1:
    print "1"
elif k%n == 0:
    if n%2 == 0:
        print k
    else:
        print k-1
else:
    p = int(k/n) * n
    k = k - p
    if n%2 == 0:
        if k > n/2:
            print p + (2*(k- n/2))
        else:
            print p + (2*k - 1)
    else:
        if k > (n+1)/2:
            print p + (2*(k- (n+1)/2))
        else:
           print p + (2*k - 1)