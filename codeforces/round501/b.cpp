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
    int jabba;
    cin >> jabba;
    string a,b;
    cin >> a >> b;
    if(a.length() != b.length()){
        cout << "-1";
        return 0;
    }
    int f1[26] = {0};
    int f2[26] = {0};
    for(int i = 0; i < a.length(); ++i){
        f1[a[i]-'a']++;
        f2[b[i]-'a']++;
    }
    for(int i = 0; i < 26; ++i){
        if(f1[i] != f2[i]){
            cout << "-1";
            return 0;
        }
    }
    V<int> m;
    int moves = 0;
    for(int i = 0; i < a.length(); ++i){
        if(a[i] == b[i])continue;
        int j;
        for(j = i+1; a[j] != b[i]; ++j);
        while(a[i] != b[i]){
            moves++;
            swap(a[j-1],a[j]);
            moves++;
            m.pb(j);
            j--;
        }
    }
    // cout << a << endl << b << endl;
    if(moves > 10000){
        cout << "-1";
    }else{
        cout << m.size() << endl;
        for(int i = 0; i < m.size(); ++i){
            cout << m[i] << " ";
        }
    }
    return 0;
}