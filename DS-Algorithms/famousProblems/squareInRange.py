import math
a = input()
b = input()
c = int(math.sqrt(a))
if c*c < a:
    c = c + 1
i = 1
while c*c <= b:
    print str(i) + ". " + str(c) + " squared = " + str(c*c)
    c = c + 1
    i = i + 1 