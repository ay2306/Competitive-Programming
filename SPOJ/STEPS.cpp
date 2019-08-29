#include<iostream>

int main(){
    int t;
    std::cin >> t;
    while(t--){
        int x,y;
        std::cin >> x >> y;
        if(x == y || x == y+2){
            std::cout << (x+y) - ((x&1)*(y&1)) << "\n";
        }else{
            std::cout << "No Number\n";
        }
    }
    return 0;
}