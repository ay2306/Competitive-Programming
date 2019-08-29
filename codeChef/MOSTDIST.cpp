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
#define MAXN 25
using namespace std;

ll answer = 0;

struct point{
    ll x;
    ll y;
    ll in;
    ll ind;
};

class cpr{
    public:
    bool operator ()(ll x, ll y){
        return x > y;
    }
};

class cpr1{
    public:
    bool operator ()(point a, point b){
        return (a.x + a.y) < (b.x + b.y);
    }
};
class cpr2{
    public:
    bool operator ()(point a, point b){
        return (a.x - a.y) < (b.x - b.y);
    }
};
class cpr3{
    public:
    bool operator ()(point a, point b){
        return (-a.x + a.y) < (-b.x + b.y);
    }
};
class cpr4{
    public:
    bool operator ()(point a, point b){
        return (-a.x - a.y) < (-b.x - b.y);
    }
};

ll XOR(ll a){
    return a^answer;
}

ll dist(ll x1, ll y1, ll x2, ll y2){
    return (abs(x1-x2) + abs(y1-y2));
}

int main(){
    FAST
    int q;
    cin >> q;
    V<point> arr(q+1);
    ll n = 0;
    priority_queue<point,V<point>,cpr1> p1;
    priority_queue<point,V<point>,cpr2> p2;
    priority_queue<point,V<point>,cpr3> p3;
    priority_queue<point,V<point>,cpr4> p4;
    while(q--){
        char a;
        cin >> a;
        if(a == '+'){
            n++;
            cin >> arr[n].x >> arr[n].y;
            arr[n].x^=answer;
            arr[n].y^=answer;
            arr[n].in = 1;
            arr[n].ind = n;
            p1.push(arr[n]);
            p2.push(arr[n]);
            p3.push(arr[n]);
            p4.push(arr[n]);
        }
        else if(a == '-'){
            ll num;
            cin >> num;
            num^=answer;
            arr[num].in = 0;
        }else{
            ll x1, y1;
            cin >> x1 >> y1;
            x1^=answer;
            y1^=answer;
            while(p1.size() && arr[p1.top().ind].in != 1)p1.pop();
            while(p2.size() && arr[p2.top().ind].in != 1)p2.pop();
            while(p3.size() && arr[p3.top().ind].in != 1)p3.pop();
            while(p4.size() && arr[p4.top().ind].in != 1)p4.pop();
            answer = 0;
            answer = max(answer, dist(p1.top().x,p1.top().y,x1,y1));
            answer = max(answer, dist(p2.top().x,p2.top().y,x1,y1));
            answer = max(answer, dist(p3.top().x,p3.top().y,x1,y1));
            answer = max(answer, dist(p4.top().x,p4.top().y,x1,y1));
            cout << answer << "\n";
        }
    }
}