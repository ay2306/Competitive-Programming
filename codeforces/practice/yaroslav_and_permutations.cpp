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
#define S set
#define MS multiset
#define M map
#define mp make_pair
#define pb push_back
#define MM multimap
#define IT iterator
#define RIT reverse_iterator
#define FAST ios_base::sync_with_stdio(false);cin.tie();cout.tie();

using namespace std;

int main(){
    M<int,int> m;
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i){
        int a;
        cin >> a;
        if(m.count(a) == 0){
            m.insert(mp(a,1));
        }else{
            m.find(a)->second++;
        }
    }
    if(n == 1){
        cout << "YES";
        return 0;
    }
    int k = 0;
    for(M<int,int>::IT itr = m.begin(); itr != m.end(); ++itr){
        if(itr->second > k){
            k = itr->second;
        }
    }
    // cout << k << " " << int((n+1)/2) << endl;
    if(k > int((n+1)/2))cout << "NO";
    else cout << "YES";
    return 0;
}