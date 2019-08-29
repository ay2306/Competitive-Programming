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
#define MAXN 1001000
using namespace std;
bool checkPal(string a){
    int i = 0;
    int j = a.length()-1;
    while(i < j){
        if(a[i] != a[j])return false;
        ++i;
        --j;
    }
    return true;
}
int main(){
    // FILE_READ
    string a;
    cin >> a;
    while(1){
        unordered_map<string,int> m;
        int cnt = 0;
        int n = a.length();
        for(int i = 0; i < n; ++i){
            for(int j = i; j < n; ++j){
                string t = "";
                for(int k = i; k <= j; ++k)t+=a[k];
                // cout << t << endl;
                if(checkPal(t)){
                    if(m[t] == 0)cnt++;
                    m[t]++;
                }
            }
        }
        cout << "The string \'" << a << "\' contains " << cnt << " palindromes.\n";
        if(cin >> a){

        }else{
            break;
        }
    }
    return 0;
}