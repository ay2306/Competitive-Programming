#include<bits/stdc++.h>
using namespace std;

void solve(){
    string a;
    cin >> a;
    map<char,char> m;
    m['A'] = 'A';
    m['H'] = 'H';
    m['I'] = 'I';
    m['M'] = 'M';
    m['O'] = 'O';
    m['T'] = 'T';
    m['U'] = 'U';
    m['W'] = 'W';
    m['V'] = 'V';
    m['X'] = 'X';
    m['Y'] = 'Y';
    m['b'] = 'd';
    m['d'] = 'b';
    m['o'] = 'o';
    m['p'] = 'q';
    m['q'] = 'p';
    m['v'] = 'v';
    m['w'] = 'w';
    m['x'] = 'x';
    int i = 0, j = a.size()-1;
    while(i <= j){
        if(m.count(a[i]) == 0 || m.count(a[j]) == 0)return void(cout << "NIE\n");
        if(m[a[i]] != a[j] || m[a[j]] != a[i])return void(cout << "NIE\n");
        ++i,--j;
    }
    cout << "TAK\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)solve();
    return 0;
}