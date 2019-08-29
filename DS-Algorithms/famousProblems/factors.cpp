#include<iostream>
using namespace std;

int main(){
    unsigned long long int a;
    cin >> a;
    cout << "1 x " << a << endl;
    int c = 1;
    for(int i = 2; i < (a/c); ++i){
        if(a%i == 0){
            c = i;
            cout << i << " x " << a/c << endl;
        }
    }
return 0;
}