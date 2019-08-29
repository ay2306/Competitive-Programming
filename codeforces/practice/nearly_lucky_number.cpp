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
    cin >> a;
    int l = 0;
    for(int i = 0; i < a.length(); ++i){
        if(a[i] == '4' || a[i] == '7')l++;
    }
    if(l){
        while(l){
            if(l%10 != 4 && l%10 != 7){
                cout << "NO";
                return 0;
            }
            l/=10;
        }
        cout << "YES";
    }else{
        cout << "NO";
    }
    return 0;
}