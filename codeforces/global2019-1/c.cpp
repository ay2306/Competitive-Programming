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
unordered_map<ll,int> m;
int main(){
    // FILE_READ_OUT
    int q = 1;
    cin >> q;
m[1] = 0;
m[3] = 1;
m[7] = 1;
m[15] = 5;
m[31] = 1;
m[63] = 21;
m[127] = 1;
m[255] = 85;
m[511] = 73;
m[1023] = 341;
m[2047] = 89;
m[4095] = 1365;
m[8191] = 1;
m[16383] = 5461;
m[32767] = 4681;
m[65535] = 21845;
m[131071] = 1;
m[262143] = 87381;
m[524287] = 1;
m[1048575] = 349525;
m[2097151] = 299593;
m[4194303] = 1398101;
m[8388607] = 178481;
m[16777215] = 5592405;
m[33554431] = 1082401;

        // for(int i = 1; i < 26; ++i){
        //     ll ans = 0;
        //     ll a = (1LL << i)-1;
        //     for(int j = 1; j < a; ++j){
        //         ll e = a&j;
        //         ll f = a^j;
        //         ans = max(__gcd(e,f),ans);
        //     }
        //     cout << "m[" << a << "] = " << ans << ";\n";

        // }
    while(q--){
        ll a;
        ll ans = 0;
        cin >> a;
        ll t = a;
        int b = 0;
        bool z = false;
        while(t){
            b++;
            if(t % 2 == 0)z = true;
            t/=2;
        }
        if(z){
            for(int i = 0; i < b; ++i)ans+=(1LL << i);
        }else{
            ans = m[a];
        }
        cout << ans << "\n";
    }

    return 0;

}