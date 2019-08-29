#include<iostream>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        long long int a,b;
        cin >> a >> b;
        if(a == 0 || b == 0){
            cout << 0 << " " << a << "\n";
        }else{
            cout << a/b << " " << a%b << "\n";
        }
    }
    return 0;
}