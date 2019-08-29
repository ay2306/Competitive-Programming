#include<iostream>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        string a;
        cin >> a;
        for(int i = 0; i < a.length(); ++i){
            if(a[i]=='m'){
                if(i!=0){
                    if(a[i-1]=='s'){
                        a[i-1]='S';
                        continue;
                    }
                }
                if(i!=a.length()-1){
                    if(a[i+1]=='s'){
                        a[i+1]='S';
                        continue;
                    }
                }
            }
        }
        int m = 0;
        int s = 0;
        for(int i = 0; i < a.length(); ++i){
            if(a[i]=='m')m++;
            else if(a[i]=='s')s++;
        }
        if(m == s)cout << "tie\n";
        else if(m > s)cout << "mongooses\n";
        else if(m < s)cout << "snakes\n";
    }
return 0;
}