#include<iostream>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        string a;
        cin >> a;
        int cnt = 0;
        for(int i = 0; i < a.size()-1; i+=2){
            if(a[i]=='<' && i!=(a.size()-1)){
                if(a[i+1]=='>')cnt++;
            }
            else if(a[i]=='>' && i>0){
                if(a[i-1]=='<')cnt++;
            }
        }
        cout << cnt << endl;
    }
return 0;
}