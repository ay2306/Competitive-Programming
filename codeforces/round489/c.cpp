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
#define MOD 1000000007
#define FAST ios_base::sync_with_stdio(false);cin.tie();cout.tie();

using namespace std;

ull moduloPower(ull base, ull exponent){
    if(exponent == 1)return base%MOD;
    if(exponent == 0)return 1;
    if(exponent%2 == 1){
        return ((base%MOD)*moduloPower(base,exponent-1))%MOD;
    }else{
        ull k = ((base%MOD)*(base%MOD))%MOD;
        return moduloPower(k,exponent/2);
    }
}

int main(){
    ull n,k;
    cin >> n >> k;
    if(k==0){
        cout << 2*n;
    }else{
        ull a = moduloPower(2,k+1);
        a = ((a%MOD)*(n%MOD))%MOD;
        ull b = moduloPower(2,k);
        ull c = ((a%MOD) - (b%MOD))%MOD;
        cout << c+1;
    }
    return 0;
}