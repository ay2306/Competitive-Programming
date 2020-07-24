//https://codeforces.com/contest/456/problem/B
#include<bits/stdc++.h>
using namespace std;

int main(){
    int rem = 0;
    string a;
    cin >> a;
    for(char i : a)rem = (rem*10 + i - '0')%4;
    cout << int(pow(1,rem)+pow(2,rem)+pow(3,rem)+pow(4,rem))%5;
    return 0;
}