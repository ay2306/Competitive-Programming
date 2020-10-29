#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,pref = 0;
    scanf("%d",&n);
    vector<int> a(n);
    map<int,int> m;
    for(int &i: a)scanf("%d",&i);
    m[0] = -1;
    for(int i = 0; i < n; ++i){
        pref+=a[i];
        pref%=n;
        if(m.count(pref)){
            printf("%d\n",i-m[pref]);
            for(int j = m[pref]+1; j <= i; ++j)printf("%d\n",a[j]);
            return 0;
        }
        m[pref] = i;
    }
    printf("0");
    return 0;
}