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
    ull x,y,a,b,g,c=0;
    ull arr1[3] = {0,0,0};
    ull arr2[3] = {0,0,0};
    cin >> a >> b;
    while(a){
        bool t = false;
        if(a%2 == 0){
            arr1[0]++;
            a/=2;
            t = true;
        }
        if(a%3 == 0){
            arr1[1]++;
            a/=3;
            t = true;
        }
        if(a%5 == 0){
            arr1[2]++;
            a/=5;
            t = true;
        }
        if(!t){
            x = a;
            break;
        }
    }
    while(b){
        bool t = false;
        if(b%2 == 0){
            arr2[0]++;
            b/=2;
            t = true;
        }
        if(b%3 == 0){
            arr2[1]++;
            b/=3;
            t = true;
        }
        if(b%5 == 0){
            arr2[2]++;
            b/=5;
            t = true;
        }
        if(!t){
            y = b;
            break;
        }
    }
    if(x!=y)cout << "-1";
    else{
        ll ans=0;
        for(int i = 0; i < 3; ++i){
            ll c =arr1[i]-arr2[i];
            if(c<0)c*=-1;
            ans+=c;
        }
        cout << ans;
    }
    return 0;
}