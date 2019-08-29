import sys
def res(a):
    global dict
    if a in dict:
        dict[a] = dict[a] + 1
        return a+str(dict[a])
    else:
        dict[a] = 0
        return "OK"
n = int(sys.stdin.readline())
dict = {}
for i in range(n):
    a = input()
    sys.stdout.write(res(a)+"\n")