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
#define MAXN 1001000
using namespace std;

bool pos(int a, int b){
    unordered_map<int,int> m;
    for(int i = 0; i < 5; ++i){
        m[a%10]++;
        m[b%10]++;
        a/=10;
        b/=10;
    }
    for(auto i: m){
        if(i.second > 1)return false;
    }
    return true;
}

void solve(int a){
    int i = 1234;
    int d = 0;
    while(1){
        if(i*a <= 98765 && pos(i,i*a)){
            d++;
            if(i*a < 10000)cout << "0";
            cout << i*a << " / ";
            if(i < 10000)cout << "0";
            cout << i << " = " << a << "\n";
            // return;
        }
        i++;
        if(i > 98765)break;
    }
    if(d == 0){
        cout << "There are no solutions for " << a << ".\n";
    }
}

int main(){
    FILE_READ
    int k = 1;
    while(1){
        int n;
        cin >> n;
        if(n == 0)return 0;
        if(k!=1)cout << "\n";
        solve(n);
        ++k;
    }
    return 0;
}