#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    int cur = n,val = 1;
    vector<int> a;
    while(cur){
        int to_delete = n/val - n/(val<<1);
        if(cur == 1 && val+val/2 <= n)return printf("%d",val/2+val),0;
        if(cur == 1)return printf("%d",val),0;
        cur-=to_delete;
        while(to_delete--)printf("%d ",val);
        val<<=1;
    }
    return 0;
}