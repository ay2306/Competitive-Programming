#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= 4; ++i){
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        a = min(a,b);
        b = min(c,d);
        if(a+b <= n)return printf("%d %d %d\n",i,a,n-a),0;
    }
    return printf("-1"),0;   
}