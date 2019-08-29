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
    int k,l,m,n,d;
    cin >> k >> l >> m >> n >> d;
    int *v = (int*)calloc(d+1,sizeof(int));
    for(int i = 1; i*k <= d; ++i)v[i*k]++;
    for(int i = 1; i*l <= d; ++i)v[i*l]++;
    for(int i = 1; i*m <= d; ++i)v[i*m]++;
    for(int i = 1; i*n <= d; ++i)v[i*n]++;
    int c = 0;
    for(int i = 0; i <= d; ++i){
        if(v[i])c++;
    }
    cout << c;
    return 0;
}