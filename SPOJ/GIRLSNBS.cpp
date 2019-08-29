#include<bits/stdc++.h>
using namespace std;

int main(){
    while(1){
        int a,b;
        cin >> a >> b;
        if(a == -1)break;
        if(a > b)swap(a,b);
        if(b-a <= 1)cout << "1\n";
        else{
            if(a == 0){
                cout << b << "\n";
            }else{
                cout << max(1,b-a-1) << "\n";
            }
        }
    }
    return 0;
}