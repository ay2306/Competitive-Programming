#include<iostream>
#include<limits.h>
using namespace std;


int main(){
    int n,q;
    cin >> n >> q;
    int max=-1;
    int min=INT_MAX;
    int a;
    for(int i = 0; i < n;++i){
        cin >> a;
        if(a>max)max=a;
        if(a<min)min=a;
    }
    for(int i = 0; i < q; ++i){
        cin >> a;
        if(a>=min && a<=max){
            cout << "Yes\n";
        }else{
            cout << "No\n";
        }
    }
return 0;
}