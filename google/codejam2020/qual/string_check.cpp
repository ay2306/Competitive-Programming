#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("inp","w",stdin);
    string a,b;
    cin >> a >> b;
    printf("STRING LENGTH = %d\n",(int)a.size());
    loop(i,0,a.size()){
        if(a[i] != b[i])printf("_%c_",a[i]);
    }
    printf("\n");
    int cnt = 0;
    loop(i,0,a.size()){
        if(a[i] != b[i])printf("_%c_",b[i]),cnt++;
    }
    printf("\n");
    printf("TOTAL UNMATCHED = %d\n",cnt);
    return 0;
}