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

ll dis(ll x1,ll y1){
    return sqrt((x1*x1)+(y1*y1));
}

int main(){
    ll n,xsum =0,ysum=0;
    cin >> n;
    int *c = new int[n];
    for(int i = 0; i < n; ++i){
        ll x,y;
        cin >> x >> y;
        ll rx1 = xsum+x;
        ll ry1 = ysum+y;
        ll rx2 = xsum-x;
        ll ry2 = ysum-y;
        if(dis(rx1,ry1) > dis(rx2,ry2)){
            c[i] = -1;
            xsum = rx2;
            ysum = ry2;
        }else{
            c[i] = 1;
            xsum = rx1;
            ysum = ry1;
        }
    }
    for(int i = 0; i < n; ++i){
        cout << c[i] << " ";
    }
    return 0;
}