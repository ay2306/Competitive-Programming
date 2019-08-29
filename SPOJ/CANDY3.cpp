#include<iostream>
int main(){
    int t;
    std::cin >> t;
    while(t--){
        int n,s=0;
        std::cin >> n;
        long long int a;
        for(int i = 0; i < n; ++i){
            std::cin >> a;
            s = (s+a%n)%n;
        }
        if(s == 0)std::cout << "YES\n";
        else std::cout << "NO\n";
    }
    return 0;
}