#include<iostream>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int k;
        cin >> k;
        string a;
        cin >> a;
        long long c = 0;
        for(int i = 0; i < a.length(); ++i)if(a[i] == '1')c++;
        long long int ans = ((c)*(c+1))/2;
        cout << ans << endl;
    }
    return 0;
}