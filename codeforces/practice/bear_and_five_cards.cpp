#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> a(5);
    for(int &i: a)scanf("%d",&i);
    sort(a.begin(),a.end());
    int mx = 0;
    for(int i = 1; i < 5; ++i){
        if(a[i-1] == a[i])mx=max(mx,2*a[i]);
        if(i-2 >=0 && a[i-2] == a[i])mx = max(mx,3*a[i]);
    }
    mx = accumulate(a.begin(),a.end(),0)-mx;
    return printf("%d\n",mx),0;
}