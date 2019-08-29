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
    string a;
    cin >> a;
    for(int i = 0; i+1 < a.length(); ++i){
        if(a[i] == '1' && a[i+1] == '1'){
            cout << "No\n";
            return 0;
        }
    }
    if((a[0] == '0' && a[1] == '0')||(a[a.length()-1] == '0' && a[a.length()-2] == '0')){
        cout << "No";
        return 0;
    }
    for(int i = 1; i+1 < n; ++i){
        if(a[i-1] == '0' && a[i] == '0' && a[i+1] == '0'){
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";
    return 0;
}