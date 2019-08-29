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

void getfib(int n){
    int a = 1;
    int b = 1;
    int c = 2;
    int d = 3;
    int e = 5;
    while(e != n){
        a = b;
        b = c;
        c = d;
        d = e;
        e = c+d;
    }
    cout << a << " " << b << " " << d;
}

int main(){
    ull n;
    cin >> n;
    if(n == 0)cout << "0 0 0";
    else if(n == 1)cout << "0 0 1";
    else if(n == 2)cout << "0 1 1";
    else if(n == 3)cout << "1 1 1";
    else{
         getfib(n);
        // cout << arr[0] << " " << arr[1] << " " << arr[2];
    }
    return 0;
}