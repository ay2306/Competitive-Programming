#include<iostream>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a;
        int cnt = 0;
        bool pos = true;
        bool fullScore = false;
        for(int i = 0; i < n; ++i){
            cin >> a;
            if(a==2)pos = false;
            else{
                if(a==5)fullScore = true;    
                cnt+=a;
            }
        }
        if(pos && fullScore){
            int k = cnt/n;
            if(k>=4){
                cout << "Yes\n";
            }else{
                cout << "No\n";
            }
        }else{
            cout << "No\n";
        }
    }
return 0;
}