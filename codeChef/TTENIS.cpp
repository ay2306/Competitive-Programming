#include<iostream>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        string a;
        cin >> a;
        int c = 0;
        int o = 0;
        for(int i = 0; i < a.length(); ++i){
            if(a[i]=='1')c++;
            if(a[i]=='0')o++;
            if(c == o && c == 10){
                c = 9;
                o = 9;
            }
            else if(c==11){
                cout << "WIN\n";
                break;
            }else if(o==11){
                cout << "LOSE\n";
                break;
            }
        }
    }
    return 0;
}