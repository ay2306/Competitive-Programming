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
    FAST
    string a;
    cin >> a;
    int n = a.length();
    int i = 0;
    int ans = 0;
    string two_prev = a;
    while((a[0] == 'b' && a[n-1] == 'w') || (a[0] == 'w' && a[n-1] == 'b')){
        // cout << "HE\n";
        string prev_string = a;
        for(i = 0; i+1 < n; ++i){
            if((a[i] == 'b' && a[i+1] == 'w') || (a[i] == 'w' && a[i+1] == 'b'))continue;
            else{
                ++i;
                break;
            }
        }
        // cout << i << endl;
        if(i!=0)reverse(a.begin(),a.begin()+i);
        if(i!=0)reverse(a.begin()+i,a.end());
        if(a == prev_string || a == two_prev)break;
        two_prev = prev_string;
    }
    // cout << a << endl;
    // cout << n << endl;
    int c = 1;
    for(i = 0; i < n-1; ++i){
            // cout << "H\n";
        if((a[i] == 'b' && a[i+1] == 'w') || (a[i] == 'w' && a[i+1] == 'b'))c++;
        else{
            ans = max(c,ans);
            c = 1;
        }
    }
    ans = max(ans,c);
    cout << ans;
    return 0;
}