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
    ull *p = new ull[n];
    ull *t = new ull[n];
    int min = 0;
    for(int i = 0; i < n; ++i){
        cin >> p[i];
        if(p[i]%n == i)t[i] =p[i];
        else{
            if(p[i]%n > i){
                t[i] = p[i] + n-(p[i]%n)+i;
            }else{
                t[i] = p[i] + i - (p[i]%n);
            }
        }
        // cout << t[i] << " ";
        if(t[min] > t[i]){
            min = i;
        }
    }
    // cout << endl;
    cout << min+1;
    return 0;
}