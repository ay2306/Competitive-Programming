#include<iostream>
#include<vector>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int a,b;
        cin >> a >> b;
        for(int i = 1; true; ++i){
            if((i*i)>a){
                a=-1;
                break;
            }
            if((i*i) + i > b){
                b=-1;
                break;
            }
        }
        if(b==-1){
            cout << "Limak\n";
        }
        if(a==-1){
            cout << "Bob\n";
        }
    }
return 0;
}