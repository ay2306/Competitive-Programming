#include<iostream>
#include<math.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    const int N = 1e6+10;
    while(t--){
        long n,ans=0;
        cin >> n;
        while((1 << ans) < n)ans++;
        cout << ans+1 << "\n";
    }
    return 0;
}