#include<iostream>
using namespace std;
int setC(char c[], int i, string a, string b){
    if(i == a.length()){
        int cnt1 = 0;
        int cnt2 = 0;
        for(int k = 0; k < a.length(); ++k){
            if(c[k]!=a[k])cnt1++;
            if(c[k]!=b[k])cnt2++;
        }
        return (cnt1+cnt2);
    }else if(a[i]==b[i]){
        if(a[i]=='B')c[i]='W';
        else{c[i]='B';}
        return setC(c,i+1,a,b);
    }else{
        c[i] = 'W';
        int wResult = setC(c,i+1,a,b);
        c[i] = 'B';
        int bResult = setC(c,i+1,a,b);
        if(wResult > bResult){
            c[i]='W';
            return wResult;
        }
        return bResult;
    }
}
int main(){
    int t;
    cin >> t;
    while(t--){
        string a,b;
        cin >> a >> b;
        char *c = new char[a.length()];
        // for(int i = 0; i < a.length(); ++i)c+='W';
        setC(c,0,a,b);
        cout << c << endl;
    }
}
    