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
string ans = "";

int main(){
    int z,o;
    cin >> z >> o;
    if(2*z+2 < o || o +1  < z){
        cout << "-1";
        return 0;
    }
    if(z > o){
        for(int i = 0; i < o; ++i)ans+="01";
        ans+="0";
    }else{
        while(o > z && z > 0){
            ans+="110";
            o-=2;
            z-=1;
        }
        while(o > 0 && z > 0){
            ans+="10";
            o--;
            z--;
        }
        while(o > 0){
            ans+="1";
            o--;
        }
    }
    cout << ans;
    return 0;
}