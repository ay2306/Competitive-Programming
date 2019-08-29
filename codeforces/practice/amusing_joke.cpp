#include <bits/stdc++.h>
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
    int e[26] = {0};
    int g[26] = {0};
    // int g[26] = {0};
    string a,b,c;
    cin >> a >> b >> c;
    for(int i = 0; i < a.length(); ++i){
        e[a[i]-'A']++;
    }
    for(int i = 0; i < b.length(); ++i){
        e[b[i]-'A']++;
    }
    for(int i = 0; i < c.length(); ++i){
        g[c[i]-'A']++;
    }
    for(int i = 0; i < 26; ++i){
        if(e[i] != g[i]){
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}