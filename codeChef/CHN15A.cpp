#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,k,a,c=0;
        cin >> n >> k;
        while(n--){
            cin >> a;
            if((a+k)%7 == 0)c++;
        }
        cout << c << endl;
    }
    return 0;
}