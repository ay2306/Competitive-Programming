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
    FILE_READ
    while(1){
        int a,b;
        cin >> a >> b;
        if(a == 0 || b == 0)break;
        list<int> li;
        for(int i = 1; i <= a; ++i)li.pb(i);
        while(b--){
            int l,r;
            cin >> l >> r;
            list<int>::iterator itr = li.begin();
            while(itr != li.end() && *itr < l){
                ++itr;
                if(itr == li.end())break;
                // cout << "1";
            }
            if(itr == li.begin())cout << "* ";
            else{
                --itr;
                cout << *itr << " ";
            }
            while(itr != li.end() && *itr <= r){
                ++itr;
                if(itr == li.end())break;
                // cout << "2";
            }
            if(itr == li.end())cout << "*\n";
            else{
                cout << *itr << "\n";
            }
            for(int i = l; i <= r; ++i)li.remove(i);
        }
        cout << "-\n";
    }
    return 0;
} 