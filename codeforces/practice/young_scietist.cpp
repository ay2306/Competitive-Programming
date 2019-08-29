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
    int n;
    cin >> n;
    int a = 0,b=0,c=0;
    for(int i =0,k,l,m; i < n; ++i){
        cin >> l >> m >> k;
        a+=l;
        b+=m;
        c+=k;
    }
    // cout << a << " " << b << " " << c << endl;
    if(a == 0 && b==0 && c==0){
        cout << "YES";
    }else{
        cout << "NO";
    }
    return 0;
}