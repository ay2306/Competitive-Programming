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

struct Triple{
    int a,b,c;
    Triple():a(-1),b(-1),c(-1);
    Triple(int x, int y, int z):a(x),b(y),c(z);
    bool operater<(Triple const &other)const{return c < other.c;}
};

void solve(){
    int n;
    cin >> n;
    V<Triple> projects(n);
    loop(i,0,n){
        int a,b,c;
        cin >> a >> b >> c;
        projects[i] = Triple(a,b,c);
    }
    sort(projects.begin(),projects.end());
    int time = 0;
    double money = 0;
    priority_queue<PII,V<PII> > p;
    for(int i = 0; i < n; ++i){
        time+=projects[i].b;
        p.push(mp(projects[i].a,projects[b]));
        if(projects[i].c >= time)continue;
        while(1){
            PII temp = p.top();
            p.pop();
            if(time - temp.S <= projects[i].c){
                temp.second -= time-projects[i].c;
                
            }
        }
    }
}

int main(){
    FILE_READ_IN
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}