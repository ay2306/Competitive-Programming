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
#define MAXN 25
using namespace std;

void solve(){

    ll d;
    int n;
    cin >> n >> d;
    V<ll> arr(n);
    loop(i,0,n){
        cin >> arr[i];
    }
    V<ll> left;
    V<ll> right;
    for(int i = 1; i < n; ++i){
        if(arr[i] >= arr[0])right.pb(arr[i]);
        else left.pb(arr[i]);
    }
    sort(left.begin(),left.end());
    sort(right.begin(),right.end());
    ll prev = arr[0];
    for(int i = left.size() - 1; i >= 0; --i){
        ll k = left[i]-prev;
        if(abs(k) > d){
            cout << "NO\n";
            return;
        }
        prev = left[i];
    }
    prev = arr[0];
    for(int i = 0; i < right.size(); ++i){
        ll k = right[i]-prev;
        if(abs(k) > d){
            cout << "NO\n";
            return;
        }
        prev = right[i];
    }
    if(left.size() && right.size()){
        prev = arr[0];
        bool a = true;
        for(ll i = 1; i < right.size(); i+=2){
            ll k = prev-right[i];
            k = abs(k);
            if(k > d){
                a = false;
                break;
            }
            prev = right[i];
        }
        prev = right[0];
        for(ll i = 2; i < right.size(); i+=2){
            ll k = prev-right[i];
            k = abs(k);
            if(k > d){
                a = false;
                break;
            }
            prev =  right[i];
        }
        if(a && abs(right[0] - left[left.size()-1]) <= d){
            cout << "YES\n";
            return;
        }
        a = true;
        prev = arr[0];
        for(int i = left.size()-2; i >= 0; i-=2){
            ll k = prev-left[i];
            k = abs(k);
            if(k > d){
                a = false;
                break;
            }
            prev = left[i];
        }
        prev = left[left.size()-1];
        for(int i = left.size()-3; i >= 0; i-=2){
            ll k = prev-left[i];
            k = abs(k);
            if(k > d){
                a = false;
                break;
            }
            prev = left[i];
        }
        if(a && abs(left[left.size()-1] - right[0]) <= d){
            cout << "YES\n";
            return;
        }
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
}


int main(){
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}