#include<iostream>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        string a;
        cin >> a;
        int cnt = 0;
        char last = ' ';
        for(int i = 0; i < a.length(); ++i){
            if(a[i]=='1' && (last == ' ' || last == '0')){
                last = a[i];
                ++cnt;
            }else{
                last = a[i];
            }
        }
        // cout << cnt << endl;
        if(cnt == 1)cout << "YES\n";else{cout << "NO\n";}
    }
    return 0;
}