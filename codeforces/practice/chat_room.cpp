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
    int arr[256] = {0};
    string a;
    cin >> a;
    bool h = false;
    bool e = false;
    bool l1 = false;
    bool l2 = false;
    bool o = false;
    for(int i = 0; i < a.length(); ++i){
        if(a[i] == 'h')h = true;
        else if(a[i] == 'e' && h)e = true;
        else if(a[i] == 'l' && h && e && !l1)l1=true;
        else if(a[i] == 'l' && h && e && l1)l2=true;
        else if(a[i] == 'o' && h && e && l1 && l2)o = true;
    }
    // if(h)cout << "h";
    // if(e)cout << "e";
    // if(l1)cout << "l1";
    // if(l2)cout << "l2";
    // if(o)cout << "o";
    if(h && e && l1 && l2 && o)cout << "YES";
    else cout << "NO";
    return 0;
}