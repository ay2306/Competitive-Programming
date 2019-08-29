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
int main(){
    while(1){
        unordered_map<int,int> m;
        int flag = 1;
        int n;
        string a;
        while(1){
            cin >> n;
            if(n == 0){
                break;
            }
            cin >> a;
            cin >> a;
            if(a == "high"){
                if(m[n-1] == -1)flag = 0;
                for(int t = n; t <= 10; ++t){
                    if(m[t] == -1){
                        flag = 0;
                    }
                    m[t] = 11;
                }
            }
            if(a == "low"){
                if(m[n+1] == 11)flag = 0;
                for(int t = n; t > 0; --t){
                    if(m[t] == 11){
                        flag = 0;
                    }
                    m[t] = -1;
                }
            }
            if(a == "on"){
                if(m[n]!=0)flag = 0;
                break;
            }
        }
        if(n == 0)break;
        if(flag)cout << "Stan may be honest\n";
        else cout << "Stan is dishonest\n";
    }
    return 0;
}