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

int main(){
    M<int,int> MAP;
    int n,m;
    cin >> n >> m;
    for(int i = 0; i < m; ++i){
        int a;
        cin >> a;
        MAP[a]++;
    }
    int ans = 0;
    int low = 0;
    int high = m;
    while(low <= high && high > 0){
        int mid = (low + high)/2;
        if(mid == 0){
            mid = 1;
        }
        int people_fed = 0;
        for(M<int,int>::IT it = MAP.begin(); it != MAP.end(); ++it){
            people_fed += (it->second / mid);
        }
        if(people_fed >= n){
            low = mid+1;
            ans = max(ans,mid); 
        }else{
            high = mid-1;
        }
        // if(mid == 1)break;
    }
    cout << ans;
    return 0;
}
