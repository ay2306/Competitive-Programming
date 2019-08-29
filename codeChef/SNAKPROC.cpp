#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int k;
        cin >> k;
        int h = 0;
        int t = 0;
        char last = ' ';
        bool valid = true;
        string a;
        cin >> a;
        for(int i = 0; i < a.length(); ++i){
            if(a[i]=='H' && (last==' ' || last=='T')){
                h++;
                last = 'H';
            }
            else if(a[i]=='T' && (last=='H')){
                t++;
                last = 'T';
            }
            else if(a[i]!='.'){
                valid = false;
            }
        }
        if(valid && (h == t))cout << "Valid\n";
        else{cout << "Invalid\n";}
    }
}