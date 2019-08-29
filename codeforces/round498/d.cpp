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
#define S set
#define MS multiset
#define M map
#define mp make_pair
#define pb push_back
#define MM multimap
#define IT iterator
#define RIT reverse_iterator
#define FAST ios_base::sync_with_stdio(false);cin.tie();cout.tie();
#define FILE_READ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
using namespace std;

int main(){
    string a,b;
    int n;
    cin >> n;
    cin >> a >> b;
    V<int> ra,rb,fa,fb;
    // int n = a.length();
    for(int i = 0; i < a.length(); ++i){
        if(a[i] == b[i]){
            continue;
        }
        if(a[i] == b[n-1-i] && a[n-1-i]!=b[n-1-i]){
            swap(b[n-1-i],b[i]);
            continue;
        }
        swap(a[i],b[i]);
        if(a[i] == b[i]){
            continue;
        }
        if(a[i] == b[n-1-i] && a[n-1-i]!=b[n-1-i]){
            swap(b[n-1-i],b[i]);
            continue;
        }
        swap(a[i],b[i]);
        swap(a[n-1-i],b[n-1-i]);
        if(a[i] == b[i]){
            continue;
        }
        if(a[i] == b[n-1-i] && a[n-1-i]!=b[n-1-i]){
            swap(b[n-1-i],a[i]);
            continue;
        }
        swap(a[n-1-i],b[n-1-i]);
    }
    //     for(int i = 0; i < a.length(); ++i){
    //     if(a[i] == b[i]){
    //         continue;
    //     }
    //     if(a[i] == b[n-1-i] && a[n-1-i]!=b[n-1-i]){
    //         swap(b[n-1-i],b[i]);
    //         continue;
    //     }
    //     swap(a[i],b[i]);
    //     if(a[i] == b[i]){
    //         continue;
    //     }
    //     if(a[i] == b[n-1-i] && a[n-1-i]!=b[n-1-i]){
    //         swap(b[n-1-i],a[i]);
    //         continue;
    //     }
    //     swap(a[i],b[i]);
    //     swap(a[n-1-i],b[n-1-i]);
    //     if(a[i] == b[i]){
    //         continue;
    //     }
    //     if(a[i] == b[n-1-i] && a[n-1-i]!=b[n-1-i]){
    //         swap(b[n-1-i],a[i]);
    //         continue;
    //     }
    //     swap(a[n-1-i],b[n-1-i]);
    // }
    int ans = 0;
    // cout << a << endl <<  b << endl;
    for(int i = 0; i < a.length(); ++i){
        if(a[i] != b[i]){
            ans++;
        }
    }
    cout << ans;
    return 0;
}