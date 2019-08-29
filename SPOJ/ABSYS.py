t = int(input())
def notNumber(a):
    a = a.strip()
    for i in a:
        if ord(i) < ord('0') or ord(i) > ord('9'):
            return True
    return False
for i in range(t):
    a = input()
    a = input()
    e = a.split('=')[0].split('+')[0]
    f = a.split('=')[0].split('+')[1]
    g = a.split('=')[1]
    if(notNumber(e)):
        e = int(g) - int(f)
        print(str(e) + ' + ' + str(f) + ' = ' + str(g))
    elif(notNumber(f)):
        f = int(g) - int(e)
        print(str(e) + ' + ' + str(f) + ' = ' + str(g))
    elif(notNumber(g)):
        g = int(e) + int(f)
        print(str(e) + ' + ' + str(f) + ' = ' + str(g))