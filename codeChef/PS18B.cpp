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

void solve(){
    int q;
    cin >> q;
    priority_queue<int,V<int>> p1;
    priority_queue<int,V<int>,greater<int>> p2;
    int tarr[2];
    int i = 0;
    while(i < 2){
        q--;
        int t,a;
        cin >> t;
        if(t == 1){
            cin >> a;
            tarr[i++] = a;
        }else{
            cout << tarr[0] << "\n";
        }
    }
    i = 1;
    p2.push(max(tarr[0],tarr[1]));
    p1.push(min(tarr[0],tarr[1]));
    while(q--){
        int t,a;
        cin >> t;
        // cout << q << endl;
        if(t == 3){
            cout << p1.size() << " " << p1.top() << endl;
            cout << p2.size() << " " << p2.top() << endl;
            q++;
        }
        else if(t == 1){
            cin >> a;
            if(a >= p1.top()){
                p2.push(a);
            }else{
                p1.push(a);
            }
            if(p2.size() > p1.size()+1){
                p1.push(p2.top());
                p2.pop();
            }else if(p1.size() > p2.size()+1){
                p2.push(p1.top());
                p1.pop();
            }
        }else{
            if((p1.size()+p2.size())%2 == 0){
                double ans = p1.top()+p2.top();
                printf("%.10f\n",ans/2);
            }else{
                if(p1.size() > p2.size())printf("%.10f\n",double(p1.top()));
                else printf("%.10f\n",double(p2.top()));
            }
        }
    }
}

int main(){
    FAST
    int t = 1;
    // cin >> t;
    while(t--)solve();
    return 0;
}