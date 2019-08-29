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
vector<int> t;
vector<int> a;
vector<int> b;

bool pos = true;

bool backTrack(int k){
    if(k == t.size())return true;
    bool s = false;
    for(int j = 0; j < 4; ++j){
        if((t[k-1]|j) == a[k-1] && (t[k-1]&j) == b[k-1]){
            t[k] = j;
            s = (s || backTrack(k+1));
            if(s){
                return true;
            }
        }
    }
    return false;
}

int main(){
    FAST
    int n;
    cin >> n;
    a = vector<int> (n-1);
    b = vector<int> (n-1);
    t = vector<int> (n);
    loop(i,0,n-1)cin >> a[i];
    loop(i,0,n-1)cin >> b[i];
    for(int i = 0; i < 4; ++i){
        t[0] = i;
        if(backTrack(1)){
            cout << "YES\n";
            for(auto k: t){
                cout << k << " ";
            }
            return 0;
        }
    }
    cout << "NO\n";
    return 0;
}