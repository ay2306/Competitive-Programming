#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,x;
        scanf("%d%d",&n,&x);
        vector<int> a(n);
        for(int &i: a)scanf("%d",&i);
        *max_element(a.begin(),a.end()) > x ? printf("Yes\n") : printf("No\n");  
    }
    return 0;
}