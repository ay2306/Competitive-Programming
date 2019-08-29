#include<iostream>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        unsigned long long int a,b,n;
        cin >> a >>b >> n;
        if(n%2==1)a*=2;
        if(a>b)cout << a/b << endl;
        else{cout << b/a << endl;}
    }
return 0;
}