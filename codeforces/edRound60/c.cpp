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

const ll maxn = 1e5;

int main(){
    ll x,y;
    cin >> x >> y;
    ll dx,dy;
    cin >> dx >> dy;
    int n;
    cin >> n;
    string a;
    cin >> a;
    ll nx = 0,ny = 0;
    for(auto i: a){
        switch(i){
            case 'U': ny++;break;
            case 'D': ny--;break;
            case 'R': nx++;break;
            case 'L': nx--;break;
        }
    }
    dx-=x;
    dy-=y;
    x = 0;
    y = 0;
    map<PII,int> m;
    int steps = 1;
    for(auto i: a){
        if(i == 'U'){
            y++;
        }
        if(i == 'D'){
            y--;
        }
        if(i == 'L'){
            x--;
        }
        if(i == 'R'){
            x++;
        }
        ll a1,a2,a3,a4;
        a1 = abs(dx-x-1) + abs(dy-y);
        a2 = abs(dx-x+1) + abs(dy-y);
        a3 = abs(dx-x) + abs(dy-y-1);
        a4 = abs(dx-x) + abs(dy-y+1);
        ll mn = min(a1,min(a2,min(a3,a4)));
        if(mn == a1){
            x++;
            if(m.find(mp(x,y)) == m.end())m[mp(x,y)] = steps;
            else m[mp(x,y)] = min(steps,m[mp(x,y)]);
        }
        if(mn == a2){
            x--;
            if(m.find(mp(x,y)) == m.end())m[mp(x,y)] = steps;
            else m[mp(x,y)] = min(steps,m[mp(x,y)]);
        }
        if(mn == a3){
            y++;
            if(m.find(mp(x,y)) == m.end())m[mp(x,y)] = steps;
            else m[mp(x,y)] = min(steps,m[mp(x,y)]);
        }
        if(mn == a4){
            y--;
            if(m.find(mp(x,y)) == m.end())m[mp(x,y)] = steps;
            else m[mp(x,y)] = min(steps,m[mp(x,y)]);
        }
    }
    while(abs())

    return 0;
}