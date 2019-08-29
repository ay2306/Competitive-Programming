a = input()
print "1 x " + str(a)
i = 2
c = 1
while i < (a/c):
    if a%i == 0:
        print str(i) + " x " + str(a/c)
        c = i
    i = i + 1