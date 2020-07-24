#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    map<string,string> ip;
    while(n--){
        string a,b;
        cin >> a >> b;
        ip[b] = a;
    }
    while(m--){
        string a,b,c;
        cin >> a >> b;
        c = b;
        while(c.size() && !isdigit(c.back())){
            c.pop_back();
        }
        cout << a << " " << b << " #" << ip[c] << "\n";
    }
    return 0;
}