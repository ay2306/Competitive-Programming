#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m,d,D,cnt = 0;
        scanf("%d%d%d%d",&n,&m,&d,&D);
        if(d*n > m || D*n < m){
            printf("-1\n");
            continue;
        }
        int drift = 0, i = 0;
        while(m--){
            int a = i++;
            int b = (a + drift)%n;
            printf("%d %d\n",a+1,b+1);
            if(i == n)i = 0,drift++;
        }
    }
    return 0;
}