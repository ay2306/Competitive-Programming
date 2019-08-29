#include<iostream>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int a;
        cin >> a;
        int k;
        int lp;
        if(a>2000){
            lp = a-2001;
            lp/=4;
            if(lp>2300){
                lp-=3;
            }else if(lp>2200){
                lp-=2;
            }else if(lp>2100){
                lp--;
            }
            k = (a-2001) + lp;
            k = k % 7;
        }else if(a == 2000)k=5;
        else{
            //code to write;
        }
        switch(k){
            case 0: cout << "monday\n";break;
            case 1: cout << "tuesday\n";break;
            case 2: cout << "wednesday\n";break;
            case 3: cout << "thursday\n";break;
            case 4: cout << "friday\n";break;
            case 5: cout << "satday\n";break;
            case 6: cout << "sunday\n";break;
        }
    }
    return 0;
}