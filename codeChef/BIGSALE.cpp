#include<stdio.h>
#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        double k = 0;
        while(n--){
            int price, quantity, discount;
            cin >> price >> quantity >> discount;
            k += (price*discount*discount*quantity);
        }
        k*= 0.0001;
        printf("%12.9f\n",k);
    }
return 0;
}