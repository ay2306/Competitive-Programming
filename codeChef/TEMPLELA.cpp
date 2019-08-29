#include<iostream>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,a;
        cin >> n;
        bool pos = true;
        int *arr =  new int[n];
        if(n%2==0){
            pos = false;
            for(int i = 0; i < n; ++i){
                cin >> a;
            }
        }else{
            int mid = n/2;
            for(int i = 0; i <= mid; ++i){
                cin >> a;
                if(a != (i+1)){
                    pos = false;
                }
            }
            for(int i = mid+1; i < n; ++i){
                cin >> a;
                if(a!=(n - i)){
                    pos = false;
                }
            }
        }
        if(pos)cout << "yes\n";
        if(!pos)cout << "no\n";
    }
}