#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t;
    cin >> t;
    while(t--){
        int a,b;
        cin >> a >> b;
        int c = (a*a) + (b*b);
        int d = (max(a,b)*max(a,b))-(min(a,b)*min(a,b));
        long double e = sqrt(c);
        if((e-floor(e)) == 0){
            cout << "yes\n";
            continue;
        }
        e = sqrt(d);
        if((e-floor(e)) == 0){
            cout << "yes\n";
            continue;
        }        
        cout << "no\n";
    }
}