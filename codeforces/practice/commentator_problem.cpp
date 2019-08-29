/*
 ____________________________________________________________
|                                                            |
|                   Author: ay2306                           |
|____________________________________________________________|

*/
#include <bits/stdc++.h>
#define MOD 1000000007
#define test int t; cin>>t; while(t--)
#define init(arr,val) memset(arr,val,sizeof(arr))
#define loop(i,a,b) for(int i=a;i<b;i++)
#define loopr(i,a,b) for(int i=a;i>=b;i--)
#define loops(i,a,b,step) for(int i=a;i<b;i+=step)
#define looprs(i,a,b,step) for(int i=a;i>=b;i-=step)
#define ull unsigned long long int
#define ll long long int
#define P pair
#define PLL pair<long long, long long>
#define PII pair<int, int>
#define PUU pair<unsigned long long int, unsigned long long int>
#define L list
#define V vector
#define D deque
#define ST set
#define MS multiset
#define M map
#define UM unordered_map
#define mp make_pair
#define pb push_back
#define pf push_front
#define MM multimap
#define F first
#define S second
#define IT iterator
#define RIT reverse_iterator
#define FAST ios_base::sync_with_stdio(false);cin.tie();cout.tie();
#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);
using namespace std;
const double eps = 1e-5;
const ll maxn = 1e5;
struct point{
    double x;
    double y;
    point(){}
    point(double a, double b):x(a),y(b){}
};

struct circle;
struct line;

struct line{
    double a;
    double b;
    double c;
    line(){};
    line(double A, double B, double C):a(A),b(B),c(C){}
    line(circle A):a(A.x),b(A.y),c(A.r){}
};
struct circle{
    double x;
    double y;
    double r;
    circle(){}
    circle(line A):x(A.a),y(A.b),r(A.c){}
    circle(double A, double B, double C):x(A),y(B),r(C){}
};


double dist(point a, point b){
    return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}
template<class T>
T determinant(V<V<T> > arr){
    if(arr.size() == 2)return arr[0][0]*arr[1][1] - arr[0][1]*arr[1][0];
    T ans = 0;
    for(int k = 0; k < arr.size(); ++k){
        V<V<T> > a;
        for(int i = 0; i < arr.size(); ++i){
            V<T> b;
            for(int j = 0; j < arr.size(); ++j){
                if(i == k || j == k)continue;
                b.pb(arr[i][j]);
            }
            if(b.size() > 0)a.pb(b);
        }
        if(k%2 == 0)ans+=(arr[0][k]*determinant(a));
        if(k%2 == 1)ans-=(arr[0][k]*determinant(a));
    }
    return ans;
}

int lines_intersection(line a, line b, point &A){
    V<V<double> > det(2, V<double> (2));
    det[0][0] = a.a;
    det[0][1] = a.b;
    det[1][0] = b.a;
    det[1][1] = b.b;
    double d = determinant(det);
    if(abs(d) < eps)return 0;
    det = V<V<double> > (2, V<double> (2));
    det[0][0] = -a.c;
    det[0][1] = a.b;
    det[1][0] = -b.c;
    det[1][1] = b.b;
    A.x = determinant(det)/d;
    det = V<V<double> > (2, V<double> (2));
    det[0][0] = a.a;
    det[0][1] = -a.c;
    det[1][0] = b.a;
    det[1][1] = -b.c;
    A.y = determinant(det)/d;
    return 1;
}

int line_circle_interaction(line a, circle b, point &A, point &B){
    if(abs(a.b) <= eps){
        double d = abs(b.x + a.c / a.a);
        if(d > b.r){
            return 0;
        }else if(abs(d-b.r) <= eps){
            A.x = -a.c/a.a;
            A.y = b.y;
            return 1;
        }else{
            A.x = B.x = -a.c/a.a;
            A.y = b.y + sqrt(b.r * b.r - d * d);
            B.y = b.y - sqrt(b.r * b.r - d * d);
            return 2;
        }
    }else if(abs(a.a) < eps){
        double d = abs(b.y + a.c/a.b);
        if(d > b.r){
            return 0;
        }else if(abs(d-b.r) <= eps){
            A.y = -a.c/a.b;
            A.x = b.x;
            return 1;
        }else{
            A.y = B.y = -a.c/a.b;
            A.x = b.x + sqrt(b.r * b.r - d * d);
            B.x = b.x - sqrt(b.r * b.r - d * d);
            return 2;
        }
    }else{
        point C(0.0,0.0);
        lines_intersection(a, line(-a.b,a.a,-a.a*b.y + a.b*b.x),C);
        double d = dist(point(b.x,b.y),C);
        if(d > b.r){
            return 0;
        }
        else if(abs(d-b.r) <= eps){
            A.x = C.x;
            A.y = C.y;
            return 1;
        }else{
            double alpha = atan(a.a/a.b);
            double l = sqrt(b.r*b.r - d*d);
            A.x = C.x - l*cos(alpha);
            A.y = C.y + l*cos(alpha);
            B.x = C.x + l*cos(alpha);
            B.y = C.y - l*cos(alpha);
            return 2;
        }
    }
    return 2;
}

int circle_intersection(circle a, circle b, point &A, point &B){
    double d = dist(point(a.x,b.x),point(b.x,b.y));
    if(d > a.r+b.r){
        return 0;
    }else{
        double a1 = (a.r*a.r - b.r*b.r + d)/(2*d);
        point C(a1/d*(b.x-a.x) + a.x,a1/d*(b.y-a.y) + a.y);
        double c = a.y-b.y;
        double d = b.x-a.y;
        int ans;
        if(abs(a.x-b.x)<=eps){
            ans = line_circle_interaction(line(0,1,-C.y),a,A,B);
        }else{
            ans = line_circle_interaction(line(-c,-d,-C.y*c + d * C.x),a,A,B);
        }
        return ans;
    }
}

int line_form(circle a, circle b, line &A){
    if(abs(a.r-b.r) < eps){
        double a1 = a.y-b.y;
        double b1 = b.y-a.y;
        double x1 = (a.x + b.x)/2;
        double y1 = (a.y + b.y)/2;
        A.a = -b1;
        A.b = a1;
        A.c = -a1*y1 + b1*x1;
        return 1;
    }else{
        double d = dist(point(a.x,a.y),point(b.x,b.y));
        double s = a.r*a.r /b.r/b.r;
        A.a = (a.x - s * b.x)/(1-s);
        A.b = (a.y - s * b.y)/(1-s);
        A.c = abs(d*a.r/b.r/(1-s));
        return 2;
    }
    return -1;
}

int main(){
    circle inp[3];
    loop(i,0,3)cin >> inp[i].x >> inp[i].y >> inp[i].r;
    line l1,l2;
    int c1c2 = line_form(inp[0],inp[1],l1);
    int c2c3 = line_form(inp[1],inp[2],l2);
    if(c1c2 == 1 && c2c3 == 1){
        point a;
        int ans = lines_intersection(l1,l2,a);
        if(ans){
            cout << fixed << setprecision(10) << a.x << " " << a.y;
        }else{
            return 0;
        }
    }else if(c1c2 * c2c3 == 2){
        point a,b;
        int ans;
        if(c1c2 == 1){
            ans = line_circle_interaction(l1,l2,a,b);
        }else{
            ans = line_circle_interaction(l2,l1,a,b);
        }
        if(ans == 0){
            return 0;
        }else if(ans == 1){
            cout << fixed << setprecision(10) << a.x << " " << a.y;
        }else{
            if(dist(point(inp[0].x,inp[0].y),a) > dist(point(inp[0].x,inp[0].y),a))swap(a,b);
            cout << fixed << setprecision(10) << a.x << " " << a.y;
        }
    }else{
        point a,b;
        int ans = circle_intersection(l1,l2,a,b);
        if(ans == 0){
            return 0;
        }else if(ans == 1){
            cout << fixed << setprecision(10) << a.x << " " << a.y;
        }else{
            if(dist(point(inp[0].x,inp[0].y),a) > dist(point(inp[0].x,inp[0].y),a))swap(a,b);
            cout << fixed << setprecision(10) << a.x << " " << a.y;
        }
    }
    return 0;
}