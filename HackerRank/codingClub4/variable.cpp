#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("list.txt","w",stdout);
    for(int i = 1; i <= 10000; ++i){
        for(int j = i+1; j <= 10000; ++j){
            int a = i,b = j;
            int c = (a*a) + (b*b);
            int d = (max(a,b)*max(a,b))-(min(a,b)*min(a,b));
            long double e = sqrt(c);
            if((e-floor(e)) == 0){
                cout << i << " " << j << "\n";
                continue;
            }
            e = sqrt(d);
            if((e-floor(e)) == 0){
                cout << i << " " << j << "\n";
                continue;
            }        
        }
    }
}