#include<iostream>

int main(){
    long ans[110];
    ans[1] = 1;
    for(long i = 2; i < 110; ++i){
        ans[i] = ans[i-1] + i*i;
    }
    while(1){
        long a;
        std::cin >> a;
        if(a == 0)break;
        std::cout << ans[a] << "\n";
    }
    return 0;
}