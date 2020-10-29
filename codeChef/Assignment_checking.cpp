#include<bits/stdc++.h>
using namespace std;

string f(char s){
    string ans = "";
    ans+=s;
    ans+="Cov(";
    ans+=s;
    ans+=")";
    return ans;
}

int main(){
    int kk = 6;
    double ans = 0;
    double res[6] = {};
    while(kk--){
        string a;
        cin >> a;
        if(a[0] >= 'A' && a[1] <= 'F'){
            double op = 0.5;
            int n = a.size();
            if(n > 6 && a == f(a[0]))op+=0.5;
            res[a[0]-'A'] = max(res[a[0]-'A'],op);
        }
    }
    cout << accumulate(res,res+6,0.0) << " out of 6\n";
    return 0;
}