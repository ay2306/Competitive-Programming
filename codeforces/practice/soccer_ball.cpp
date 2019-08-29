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
V<string> arr;
bool check(unordered_map<char,int> m){
    bool ans = true;
    for(auto i: arr){
        int a = i[0];
        int b = i[2];
        if(i[1] == '>'){
            ans = (ans && (m[a] > m[b]));
        }else{
            ans = (ans && (m[a] < m[b]));
        }
    }
    return ans;
}
int main(){
    string a = "ABCDE";
    for(int i = 0; i < 5; ++i){
        string b;
        cin >> b;
        arr.pb(b);
    }
    do{
        unordered_map<char,int> m;
        for(int i = 0; i < 5; ++i)m[a[i]] = i;
        if(check(m)){
            cout << a;
            return 0;
        }
    }while(next_permutation(a.begin(),a.end()));
    cout << "impossible";
    return 0;
}