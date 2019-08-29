#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int s = 0, a, min = INT_MAX;
        for(int i = 0 ; i < n; ++i){
            cin >> a;
            s+=a;
            if(min > a)min = a;
        }
        cout << s-(n*min) << endl;
    }
    return 0;
}