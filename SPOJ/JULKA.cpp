#include<iostream>
#include<boost/multiprecision/cpp_int.hpp>

int main(){
    int t = 10;
    while(t--){
        boost::multiprecision::cpp_int a,b,c;
        std::cin >> a >> b;
        c = (a-b)/2;
        std::cout << c+b << "\n" << c << "\n";
    }
    return 0;
}