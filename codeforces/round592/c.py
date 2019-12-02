import math
def gcd(a,b,x,y):
    if a == 0:
        return b,0,1
    d,x1,y1 = gcd(b%a,a,0,0)
    x = y1 - ((b//a)*x1)
    y = x1
    return d,x,y

def find_any_solution(a,b,c,x,y,g):
    g,x,y = gcd(abs(a),abs(b),x,y)
    if(c % g != 0):
        return False,x,y,g
    x *= (c//g)
    y *= (c//g)
    if (a < 0):
        x = -x
    if (b < 0):
        y = -y
    return True,x,y,g


def main():
    n,p,w,d = map(int,input().split())
    pos,x0,y0,g = find_any_solution(w,d,p,0,0,0)
    if not pos:
        print("-1")
        return
    k = (y0*g)//w;
    x = x0;
    y = y0;
    x_shift = abs((d//g));
    y_shift = abs((w//g));
    if(y0 < 0):
        changes = abs(y0)//y_shift + (abs(y0) % y_shift != 0);
        y+=changes*(y_shift);
        x-=changes*(x_shift);
    else:
        changes = abs(y0)//y_shift;
        y-=changes*(y_shift);
        x+=changes*(x_shift);
    # cout << x_shift << " " << y_shift << "\n";
    # cout << x << " " << y << "\n";
    z = n-(x+y);
    if(x + y > n or x < 0 or y < 0):
        print("-1")
    else:
        print(x,y,z)
main()