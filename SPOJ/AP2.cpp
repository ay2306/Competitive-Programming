#include <bits/stdc++.h>
#define loop(i,a,b) for(int i=a;i<b;i++)
#define ll long long int
#define RIT reverse_iterator
#define FAST ios_base::sync_with_stdio(false);cin.tie();cout.tie();
using namespace std;

int main(){
    FAST
    int t;
    cin >> t;
    while(t--){
        ll a,s,l;
        cin >> a >> l >> s;
        ll n = (2*s)/(a+l);
        ll d = (l-a)/(n-5);
        a = a - 2*d;
        cout << n << "\n";
        loop(i,0,n){
            cout << a + i*d << " ";
        }
        cout << "\n";
    }
   return 0;
}