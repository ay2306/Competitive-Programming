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

int abs(int a){
    if(a < 0)a*=-1;
    return a;
}

bool comp(PII a, PII b){
    if(a.second < b.second)return true;
    return false; 
}

int main(){
    int n,m,p;
    PII *d = new PII[p];
    cin >> n >> m >> p;
    V<string> arr;
    for(int i = 0; i < n; ++i){
        string a;
        cin >> a;
        arr.pb(a);
    }
    int *one = new int[n];
    int *zero = new int[n];
    for(int i = 0; i < p; ++i){
        one[i] = 0;
        zero[i] = 0;
        for(int j = 0; j < n; ++j){
            if(arr[j][i]=='1')one[i]++;
            if(arr[j][i]=='0')zero[i]++;
        }
    }
    V<string> f;
    for(int i = 0; i < m; ++i){
        string a;
        cin >> a;
        f.pb(a);
    }
    string ans = "";
    for(int i = 0; i < p; ++i){
        ans[i]+=((one[i]>zero[i])?"1":"0");
        d[i] = mp(i,abs(one[i]-zero[i]));
    }
    sort(d,d+p,comp);
    int l =0;
    bool found = true;
    while(found){
        found = false;
        for(int i = 0; i < m; ++i){
            if(ans == f[i]){
                found = true;
                break;
            }
        } 
        if(found){
            ans[d[]]
        }
    }
    return 0;
}