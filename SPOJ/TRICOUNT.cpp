#include<iostream>
int main(){
    int t;
    std::cin >> t;
    while(t--){
        long long int n;
        std::cin >> n;
        std::cout << (n*(n+2)*(2*n+1) - (n%2))/8 << "\n";
    }
    return 0;
}