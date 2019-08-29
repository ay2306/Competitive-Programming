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
    ull n;
    cin >> n;
    char a[1000];
    cin >> a;
    // ull n = strlen(a);
    S<ull> d;
    ull low = 1;
    ull high = n;
    while(low <= high){
        if(n%low == 0){
            d.insert(low);
            d.insert(n/low);
        }
        high = n/low;
        low++;
    }
    for(S<ull>::IT itr = d.begin(); itr != d.end(); ++itr){
        reverse(a, a+(*itr));
        // cout << *itr-1 << "  ";
        // cout << a << endl;
    }
    cout << a;
    return 0;
}