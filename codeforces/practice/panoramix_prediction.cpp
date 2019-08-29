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
    int v[200] ={0};
    for(int i = 2; i < 200; ++i)if(v[i] == 0)for(int j = 2; i * j < 200; ++j)v[i*j]++;
    int m,n,o;
    cin >> n >> m;
    // cout << v[n] << endl;
    for(int i = n+1; i < 200; ++i){
        if(!v[i]){
            o = i;
            break;
        }
    }
    if(o == m){
        cout << "YES";
    }else{
        // cout << o << " ";
        cout << "NO";
    }
    return 0;
}