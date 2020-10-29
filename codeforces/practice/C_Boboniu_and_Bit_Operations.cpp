#include<bits/stdc++.h>
using namespace std;

int main(){
    int ans,n,m;
    scanf("%d%d",&n,&m);
    vector<int> a(n),b(m);
    for(int &i: a)scanf("%d",&i);
    for(int &i: b)scanf("%d",&i);
    for(ans = 0; ans <= 1024; ++ans){
        bool pos = true;
        for(int i: a){
            bool found = false;
            for(int j: b){
                bool pass = true;
                for(int bit = 10; bit >= 0 && pass; --bit)
                    if((((ans>>bit)&1)^1) && (((i&j)>>bit)&1))pass = false;
                if(pass){
                    found = true;
                    break;
                }
            }
            if(!found){
                pos = false;
                break;
            }
        }
        if(pos)break;
    }
    printf("%d",ans);
    return 0;
}