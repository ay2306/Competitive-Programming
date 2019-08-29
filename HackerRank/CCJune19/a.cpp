#include<bits/stdc++.h>
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,m;
    std::cin >> n >> m;
    for(int i = 0; i < m; ++i){
        std::cout << n++ << " " << n++ << "\n";
    }
    return 0;
}