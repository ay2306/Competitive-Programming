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

struct train{
    int day;
    int lecture;
    int sad;
};

bool comp(train a, train b){
    return a.sad < b.sad;
}

bool compDay(train a, train b){
    return a.day < b.day;
}

void solve(){
    int n,d;
    cin >> n >> d;
    ll total = 0,sum = 0;
    int i,k;
    priority_queue<train,V<train>,function<bool(train,train)> > p(comp);
    V<train> a(n);
    for(i = 0; i < n; ++i){
        cin >> a[i].day >> a[i].lecture >> a[i].sad;
        total+=(a[i].sad)*(long(a[i].lecture));
    }
    sort(a.begin(), a.end(),compDay);
    k = 0;
    i = 0;
    for(k = 1; k <= d; ++k){
        while(i < n && a[i].day == k){p.push(a[i]);++i;}
        if(p.size() == 0)continue;
        train b = p.top();
        p.pop();
        sum+=b.sad;
        b.lecture--;
        if(b.lecture > 0)p.push(b);
    }
    // cout << total << " " << sum << "\n";
    cout << total-sum << "\n";
}

int main(){
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}