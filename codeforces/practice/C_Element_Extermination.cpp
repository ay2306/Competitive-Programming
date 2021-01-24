#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,x;
        scanf("%d",&n);
        stack<int> s;
        for(int i = 0; i < n; ++i){
            scanf("%d",&x);
            if(i+1 < n && s.size() && s.top() < x)continue;
            s.push(x);
        }
        x = s.top();
        s.pop();
        while(s.size() && s.top() < x)s.pop();
        s.size() ? printf("NO\n") : printf("YES\n");
    }
    return 0;
}