#include<iostream>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int a;
        cin >> a;
        if(a%5 != 0)cout << "-1\n";
        else{
            int i = 0;
            while((a*(1<<i)%10) != 0){
                ++i;
            }
            cout << i << endl;
        }
    }
    return 0;
}