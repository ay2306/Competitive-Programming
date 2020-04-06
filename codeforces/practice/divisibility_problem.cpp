//https://codeforces.com/contest/1328/problem/A
#include<iostream>
int main(){
    int t;
    std::cin>>t;
    while(t--){
        int a,b;
        std::cin >> a >> b;
        if(a%b == 0)std::cout << 0 << "\n";
        else std::cout << b-(a%b) << "\n";
    }
}