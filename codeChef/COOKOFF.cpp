#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        int a[5]={0};
        cin >> n;
        string s;
        for(int i = 0; i < n; ++i){
            cin >> s;
            if(s == "cakewalk")a[0]++;
            if(s == "simple")a[1]++;
            if(s == "easy")a[2]++;
            if(s == "easy-medium" || s == "medium")a[3]++;
            if(s == "medium-hard" || s == "hard")a[4]++;
        }
        bool NoZero = true;
        for(int i = 0; i < 5; ++i){
            if(a[i]==0){
                NoZero = false;
                break;
            }
        }
        if(NoZero)cout << "Yes\n";
        if(!NoZero)cout << "No\n";
    }
    return 0;
}