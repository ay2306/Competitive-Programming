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
using namespace std;

const ll maxn = 1e5;

int main(){
    int n,ppp;
    cin >> n >> ppp;
    unordered_map<int,int> m;
    V<int> arr(n);
    loop(i,0,n){
        cin >> arr[i];
    } 
    loop(i,0,n){
        m[arr[i]]++;
    } 
    int ans = 0;
    for(int i = 1; i <= ppp; ++i){
        int f = 0;
        if(m[i] == 0)continue;
        if(m[i+1] == 0 || m[i+2] == 0){
            ans+=m[i]/3;
        }else{
            int f = (m[i]%3 == 0)?3:m[i]%3;
            int s = (m[i]%3 == 0)?3:m[i]%3;
            int t = (m[i]%3 == 0)?3:m[i]%3;
            int sum = f/3+s/3+t/3;
            if(f > 1 && s > 1 && t > 1 && sum < 3){
                int k = min(f,min(s,t));
                m[i]-=k;
                m[i+1]-=k;
                m[i+2]-=k;
                ans+=k;
            }
        }
        ans+=m[i]/3;
    }
    m = unordered_map<int,int> ();
    int ans2 = ans;
    ans = 0;
    loop(i,0,n){
        m[arr[i]]++;
    } 
    for(int i = 1; i <= ppp; ++i){
        ans+=(m[i]/3);
        m[i] = m[i]%3;
    }
    for(int i = 1; i <= ppp; ++i){
        int f = min(m[i],m[i+1]);
        f = min(f,m[i+2]);
        ans+=f;
        m[i]-=f;
        m[i+1]-=f;
        m[i+2]-=f;
    
    }
    cout << max(ans,ans2);
    
    return 0;
}