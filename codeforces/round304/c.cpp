//https://codeforces.com/contest/546/problem/C
#include<bits/stdc++.h>
#define ll long long int 
#define mp make_pair
#define pb emplace_back
#define loop(a,b,c) for(int a = b; a < c; ++a)
#define P pair
#define PII pair<int,int>
#define PLL pair<ll,ll>
#ifdef LOCAL
#define debug(x) cout << #x << " = " << x << " ";
#define debugn(x) cout << #x << " = " << x << "\n";
#endif
#ifndef LOCAL
#define debug(x) 42;
#define debugn(x) 42;
#endif
#define V vector
#define all(a) a.begin(), a.end()
#define MAX(a) *max_element(all(a));
#define MIN(a) *min_element(all(a));
#define SUM(a) *accumulate(all(a),0LL);
#define C continue
#define R return 
using namespace std;



int solve(){
    set<set<vector<int>>> s;
    int mv = 0;
    int n;
    cin >> n;
    int k,t;
    V<int> a,b;
    cin >> k;
    a.resize(k);
    loop(i,0,k)cin >> a[i];    
    cin >> k;
    b.resize(k);
    loop(i,0,k)cin >> b[i]; 
    set<vector<int>> h;
    h.insert(a);
    h.insert(b);
    s.insert(h);
    while(true){
        // cout << "a = ";
        // loop(i,0,a.size())cout << a[i] << " ";
        // cout << "\n";
        // cout << "b = ";
        // loop(i,0,b.size())cout << b[i] << " ";
        // cout << "\n";
        if(a.size() == 0){
            cout << mv << " 2\n";
            R 0;
        }
        if(b.size() == 0){
            cout << mv << " 1\n";
            R 0;
        }
        mv++;
        h.clear();
        if(a[0] == b[0]){
            cout << "-1";
            R 0;
        }
        if(a[0] > b[0]){
            a.pb(b[0]);
            a.pb(a[0]);
        }
        if(a[0] < b[0]){
            b.pb(a[0]);
            b.pb(b[0]);
        }
        a.erase(a.begin());
        b.erase(b.begin());
        h.insert(a);
        h.insert(b);
        if(s.count(h)){
            cout << "-1\n";
            R 0;
        }
        s.insert(h);
    }
    R 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)solve();
    return 0;
}