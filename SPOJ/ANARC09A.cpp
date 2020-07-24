#include<bits/stdc++.h>

int main(){
    int tc = 1;
    char s[3000];
    while(true){
        scanf("%s",s);
        if(*s == '-')break;
        int n = strlen(s), ans = 0, opening = 0;
        for(int i = 0; i < n; ++i){
            if(s[i] == '{'){
                opening++;
                continue;
            }
            if(opening)opening--;
            else{
                ans++;
                opening++;
            }
        }
        ans+=opening/2;
        printf("%d. %d\n",tc++,ans);
    }
    return 0;
}