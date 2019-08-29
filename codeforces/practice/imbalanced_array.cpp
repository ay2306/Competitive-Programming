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

const int maxn = 1e6 + 5;
const int inf = 1e9 + 7;

ll a[maxn], L[maxn], R[maxn];
int n;
ll res;

void run(){
    stack<int> st;
    memset(L, 0, sizeof(L));
    memset(R, 0, sizeof(R));
    st.push(0);
    loop(i,1,n+1){
        while(a[i] >= a[st.top()]){
            st.pop();
        }
        L[i] = i - st.top();
        st.push(i);
    }
    st.push(n+1);
    loopr(i,n,1){
        while(a[i] > a[st.top()]){
            st.pop();
        }
        R[i] = st.top()-i;
        st.push(i);
    }
    for(int i = 0; i <= n+1; ++i){
        if(a[i] == inf)cout << "inf ";
        else cout << a[i] << " ";
    }
    cout << endl;
    
    for(int i = 0; i <= n+1; ++i){
        if(a[i] == inf)cout << "inf ";
        else cout << L[i] << " ";
    }
    cout << endl;
    for(int i = 0; i <= n+1; ++i){
        if(a[i] == inf)cout << "inf ";
        else cout << R[i] << " ";
    }
    cout << endl;
    cout << endl;

    loop(i,1,n+1)res+=(a[i]*L[i]*R[i]);
}

int main(){
    FAST
    cin >> n;
    a[0] = inf;
    a[n+1] = inf;
    loop(i,1,n+1)cin >> a[i];
    run();
    loop(i,1,n+1)a[i]*=-1;
    run();
    cout << res;
    return 0;
}