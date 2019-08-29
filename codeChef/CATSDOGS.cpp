#include<iostream>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        unsigned long long int c,d,l;
        cin >> c >> d >> l;
        int maxLegs = (c+d)*4;
        int minLegs;
        if(c <= d*2)minLegs = d*4;
        else{
            int k = c-(d*2);
            minLegs = (d+k)*4;
        }
        if(l%4 == 0){
            if(l>=minLegs && l<=maxLegs)cout << "yes\n";
            else{cout << "no\n";}
        }else{
            cout << "no\n";
        }
    }
    return 0;
}