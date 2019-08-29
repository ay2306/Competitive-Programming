#include<iostream>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        if(n==1)cout << "1\n";
        if(n==2)cout << "1 2\n";
        if(n>2){
            int max = 1;
            int smax = 0;
            for(int i = 0; i < n; ++i){
                cout << max << " ";
                int k = smax + max + 1;
                smax = max;
                max = k;
            }
            cout << endl;
        }
    }
return 0;
}