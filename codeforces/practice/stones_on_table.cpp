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
    string a;
    int n;
    cin >> n;
    cin >> a;
    int last = 0;
    int c = 0;
    for(int i = 1; i < a.length(); ++i){
        if(a[last] != a[i]){
            last = i;
        }
        else{
            c++;
        }
    }
    cout << c;
    return 0;
}