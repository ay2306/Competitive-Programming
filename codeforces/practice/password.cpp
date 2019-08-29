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
#define all(a) a.begin(),a.end()
using namespace std;

const ll maxn = 1e5;
V<int> lps;
string a;
void computeLPS(){
    int i = 1;
    int j = 0;
    while(i < a.size()){
        if(a[i] == a[j]){
            lps[i] = j+1;
            i++;
            j++;
        }
        else{
            if(j != 0)j = lps[j-1];
            else i++;
        }
    }
}

int main(){
    cin >> a;
    lps = V<int> (a.size(),0);
    computeLPS();
    unordered_map<int,int> m;
    string no_ans = "Just a legend";
    if(lps[a.size()-1] == 0){
        cout << no_ans;
        return 0;
    }
    loop(i,0,a.size())m[lps[i]]++;
    if(m[lps[a.size()-1]] > 1){
        string ans = "";
        loop(i,0,lps[a.size()-1]){
            ans+=a[i];
        }
        cout << ans;
        return 0;
    }
    string pref = "";
    string suff = "";
    string mid = "";
    if(lps[lps[a.size()-1]-1] == 0){
        cout << no_ans;
        return 0;
    }
    int k = lps[a.size()-1] - 1;
    for(int i = 0; i < lps[k]; ++i){
        // cout << "pref " << i << " " << i << "\n";
        pref += a[i];
    }
    for(int i = 0; i < lps[k]; ++i){
        // cout << "pref " << i << " " << a.size()-1-i << "\n";
        // cout << "suff " << i << "\n";
        suff += a[a.size()-i-1];
    }
    reverse(all(suff));
    for(int i = 0; i < lps[k]; ++i){
        // cout << "mid " << i << " " << k-i << "\n";
        mid += a[k-i];
    }
    reverse(all(mid));
    // for(int i = 0; i < a.size(); ++i)cout << lps[i] << " ";
    // cout << "\n";
    // cout << k << "\n";
    // cout << pref << "\n";
    // cout << mid << "\n";
    // cout << suff << "\n";
    if(pref == suff && pref == mid){
        cout << pref;
    }else{
        cout << no_ans;
    }
    return 0;
}
