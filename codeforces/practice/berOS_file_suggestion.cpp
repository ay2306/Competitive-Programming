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
int main(){
    int n;
    unordered_map<string,P<int,string> > m;
    cin >> n;
    while(n--){
        string a;
        cin >> a;
        unordered_map<string,int> check;
        for(int i = 0; i < a.length(); ++i){
            string k = "";
            for(int j = i; j < a.length(); ++j){
                k+=a[j];
                if(check.find(k) == check.end()){
                    check[k]++;
                    if(m.find(k) == m.end()){
                        m[k] = mp(0,a);
                    }
                    m[k].F++;
                }
            }
        }
    }
    cin >> n;
    while(n--){
        string a;
        cin >> a;
        if(m.find(a) == m.end()){
            cout << "0 -\n";
        }else{
            cout << m[a].F << " " << m[a].S << "\n";
        }
    }
    return 0;
}