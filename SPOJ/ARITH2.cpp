#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        ll prev;
        cin >> prev;
        char a;
        ll inp;
        while(1){
            cin >> a;
            if(a == '=')break;
            cin >> inp;
            if(a == '+'){
                prev+=inp;
            }
            if(a == '/'){
                prev/=inp;
            }
            if(a == '-'){
                prev-=inp;
            }
            if(a == '*'){
                prev*=inp;
            }
        }
        cout << prev << "\n";
    }
    return 0;
}