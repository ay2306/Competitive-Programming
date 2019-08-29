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
    string ans = "";
    cin >> a;
    for(int i = 0; i < a.length(); ++i){
        if(a[i] == '.')ans+="0";
        else if(a[i] == '-'){
            if(a[i+1] == '.'){
                ans+="1";
            }else{
                ans+="2";
            }
            ++i;
        }
    }
    cout << ans;
    return 0;
}