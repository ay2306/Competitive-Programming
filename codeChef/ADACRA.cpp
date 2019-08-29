#include<iostream>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        string a;
        cin >> a;
        int U = 0;
        int D = 0;
        char last = ' ';
        for(int i = 0; i < a.length(); ++i){
            if(a[i]=='U'){
                if(last!='U')U++;
                last = 'U';
            }else if(a[i]=='D'){
                if(last!='D')D++;
                last = 'D';
            }
        }
        cout << ((U>D)?D:U) << endl;
    }
}