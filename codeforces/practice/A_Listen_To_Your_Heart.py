def f1(x):
    a = pow(x-3,1.0/2.0) 
    b = pow((3*x+2)/2,1.0/3.0)
    c = a - b
    return pow(c,7)
def f2(x):
    a = x*x - 1984
    a = a/5  
    a = pow(a,0.5)
    a = x - a
    return a*a*a

x = 45
while(True):
    if(f1(x) == f2(x)):
        print(x)
        break
    x+=1