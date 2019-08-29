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

int main(){
    int n;
    cin >> n;
    vector<int> l(n);
    vector<int> r(n);
    loop(i,0,n)cin >> l[i];
    loop(i,0,n)cin >> r[i];
    vector<int> ans(n);
    ans[n-1] = 1;
    for(int i = n-2; i >= 0; --i){
        ans[i] = ans[i+1] + (l[i+1]-l[i]);
    }
    for(int i = 0; i < n; ++i){
        ans[i] -= r[i];
    }
    for(int i = 0; i < n; ++i){
        int cnt = 0;
        for(int j = i-1; j >= 0; --j){
            if(ans[j] > ans[i])cnt++;
        }
        if(cnt != l[i]){
            cout << "NO\n";
            return 0;
        }
        cnt = 0;
        for(int j = i+1; j < n; ++j){
            if(ans[j] > ans[i])cnt++;
        }
        if(cnt != r[i]){
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    int mn = 1;
    for(int i = 0; i < n; i++){
        mn = min(mn,ans[i]);
    }
    mn--;
    for(auto i : ans){
        cout << i-mn << " ";
    }

    return 0;
}