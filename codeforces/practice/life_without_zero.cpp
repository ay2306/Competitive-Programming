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

ull withoutZero(ull a){
    ull d = 0,k;
    while(a){
        if(a%10){
            d*=10;
            d+=(a%10);
        }
        a/=10;
    }
    a = d;
    d = 0;
    while(a){
        d*=10;
        d+=(a%10);
        a/=10;
    }
    return d;
}

int main(){
    ull a,b,c;
    ull a1,b1,c1;
    cin >> a >> b;
    c = a+b;
    // cout << "C = " << c << endl;
    a1 = withoutZero(a);
    b1 = withoutZero(b);
    c1 = withoutZero(c);   
    // cout << a1 << " " << b1 << " " << c1 << endl;
    if(a1+b1 == c1)cout << "YES";
    else cout << "NO";
    return 0;
}