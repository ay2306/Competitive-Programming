import math
inp = raw_input()
x = int(inp.split(' ')[0])
y = int(inp.split(' ')[1])
a = float(y)/x
if (x == y):
    print "="
elif (x == 1):
    print "<"
else:
    b = math.log(y)
    c = math.log(x)
    d = b/c
    # print a 
    # print d
    if(a == d):
        print "="
    if(a > d):
        print ">"
    if(a < d):
        print "<"