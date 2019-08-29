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
#define FILE_READ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define MAXN 25
using namespace std;
int u = 0;
int r = 0;
int l = 0;
int d = 0;
int v = 0;
int h = 0;
string a;
int n;

bool pos(int k){
    int u1 = 0;
    int r1 = 0;
    int l1 = 0;
    int d1 = 0;
    int v1 = 0;
    int h1 = 0;
    for(int i = 0; i < k; ++i){
        switch(a[i]){
            case 'U': u1++;
                      v1++;
                      break;
            case 'D': d1++;
                      v1++;
                      break;
            case 'R': r1++;
                      h1++;
                      break;
            case 'L': l1++;
                      h1++;
                      break;
        }
    }
    if(u1 >= u && d1 >= d && l1 >= l && r1 >= r && h1 >= h && v1 >= v)return true;
    for(int i = k; i < n; ++i){
        switch(a[i-k]){
            case 'U': u1--;
                      v1--;
                      break;
            case 'D': d1--;
                      v1--;
                      break;
            case 'R': r1--;
                      h1--;
                      break;
            case 'L': l1--;
                      h1--;
                      break;
        }
        switch(a[i]){
            case 'U': u1++;
                      v1++;
                      break;
            case 'D': d1++;
                      v1++;
                      break;
            case 'R': r1++;
                      h1++;
                      break;
            case 'L': l1++;
                      h1++;
                      break;
        }
        if(u1 >= u && d1 >= d && l1 >= l && r1 >= r && h1 >= h && v1 >= v)return true;
    }
    return false;
}

int main(){
    cin >> n;
    cin >> a;
    ll x,y;
    cin >> x >> y;
    ll x1 = 0;
    ll y1 = 0;
    if(abs(x)+abs(y) > a.size()){
        cout << -1;
        return 0;
    }
    if((abs(x)+abs(y))%2 != a.size()){
        cout << -1;
        return 0;
    }
    for(int i = 0; i < a.size(); ++i){
        switch(a[i]){
            case 'U': y1++;
                      break;
            case 'D': y1--;
                      break;
            case 'R': x1++;
                      break;
            case 'L': x1--;
                      break;
        }
    }
    if(x1 == x && y == y1){
        cout << "0";
        return 0;
    }
    if(x1 > x){
        if((x1-x)%2 == 0){
            r=(x1-x)/2;
        }else{
            if(y1 > y){
                if((y1-y)%2 == 1){
                    u = d/2;
                    v = 1;
                }else{
                    u = d/2 + 1;
                }
            }
        }
    }
    ll low = 1;
    ll high = n;
    ll ans = LLONG_MAX;
    while(low < high){
        ll mid = (low+high)/2;
        if(pos(mid)){
            ans = min(mid,ans);
            high = mid-1;
        }else{
            low = mid+1;
        }
    }
    cout << ans;
    return 0;
}