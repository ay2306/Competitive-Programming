#include<bits/stdc++.h>
int att[15];
int def[15];

int main(){
    while(1){
        int a,d;
        std::cin >> a >> d;
        if(a == 0 && d == 0)break;
        for(int i = 0; i < a; ++i)std::cin >> att[i];
        for(int i = 0; i < d; ++i)std::cin >> def[i];
        std::sort(att,att+a);
        std::sort(def,def+d);
        if(att[0] >= def[1]){
            std::cout << "N\n";
        }else{
            std::cout << "Y\n";
        }
    }
    return 0;
}