#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    scanf("%d",&n);
    vector<int> a(n),b(n);
    vector<pair<int,int>> s(n);
    for(int i = 0; i < n; ++i){
        scanf("%d",&s[i].first);
        s[i].second = i;
    }
    sort(s.begin(),s.end());
    int len = (n+2)/3;
    for(int i = 0; i < len; ++i){
        a[s[i].second] = i;
	    b[s[i].second] = s[i].first - i;
    }
    for(int i = len; i < 2*len && i < n; ++i){
        b[s[i].second] = i;
	    a[s[i].second] = s[i].first - i;
    }
    for(int i = 2*len; i < n; ++i){
        b[s[i].second] = n-1-i;
	a[s[i].second] = s[i].first - b[s[i].second];
    }
    printf("YES\n");
    for(int i: a)printf("%d ",i);
    printf("\n");
    for(int i: b)printf("%d ",i);
    return 0;
}
