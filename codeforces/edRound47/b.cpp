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
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
using namespace std;

// bool comp(char a, char b){
//     if(a == '1' && b == '0')return false;
//     if(a == '2' && b == '1')return false;
//     if((a == '0' || a == '2') && (b == '0' || b == '2'))return false;
//     return true;
// }

int main(){
    // FILE_READ
    FAST
    ll itc = 0;
    string a;
    cin >> a;
    deque<int> o,t,z;
    for(int i = 0; i < a.length(); ++i){
        if(a[i] == '0')z.pb(i);
        if(a[i] == '1')o.pb(i);
        if(a[i] == '2')t.pb(i);
    }
    while(z.size() &&  z[0] < t[0]){
        cout << "0";
        z.pop_front();
    }
    while(o.size()){
        cout << "1";
        o.pop_front();
    }
    while(z.size() && t.size()){
        if(z[0] < t[0]){
            cout << "0";
            z.pop_front();
        }else{
            cout << "2";
            t.pop_front();
        }
    }
    while(t.size()){
        cout << "2";
        t.pop_front();
    }
    while(z.size()){
        cout << "0";
        z.pop_front();
    }
    // int n = strlen(a);
    // bool it = true;
    // while(it){
    //     itc++;
    //     it = false;
    //     for(int i = 1; i < a.length(); ++i){
    //         if(a[i-1] == '2' && a[i] == '0' && i+1 < a.length() && a[i+1] =='1'){
    //             a[i-1] = '1';
    //             a[i] = '2';
    //             a[i+1] = '0';
    //             it = true;
    //         } 
    //         if(a[i] == '0' && a[i-1] == '1'){
    //             swap(a[i],a[i-1]);
    //             it = true;
    //         }
    //         if(a[i] == '1' && a[i-1] == '2'){
    //             swap(a[i],a[i-1]);
    //             it = true;
    //         }
    //     }
    // }
    // sort(a,a+n,comp);
    // cout << a ;
    // cout << endl << itc;
    return 0;
}