#include<iostream>
#define d double
#include<math.h>

using namespace std;

int main(){
    ud x,y;
    cin >> x >> y;
    d a = y/x;
    d b = log(y)/log(x);
    if(a == b)cout << "=";
    if(a > b)cout << ">";
    else cout << "<";
    return 0;

}