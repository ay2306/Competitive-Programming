//https://codeforces.com/problemset/problem/578/C
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 2e5+10;
const long double zero = 0, eps = 1e-12;
int n;
long double a[N],b[N],neg,pos,ans;

long double SUM(){
    long double s1 = 0, s2 = 0,sum = 0;
    for(int i = 0; i < n; ++i){
        s1+=b[i];
        sum = max(sum,s1);
        s1 = max(zero,s1);
    }
    return sum;
}

int main(){
    scanf("%d",&n);
    for(int i = 0; i < n; ++i)scanf("%Lf",a+i);
    long double high = 1e17, low = -1e17, m;
    while(high-low > eps){
        m = (low + high)/2;
        for(int i = 0; i < n; ++i)b[i]=a[i]-m;
        pos = SUM();
        for(int i = 0; i < n; ++i)b[i]=m-a[i];
        neg = SUM();
        if(pos > neg)low = m;
        else high = m;
        ans = max({abs(neg),abs(pos)});
    }
    printf("%.12Lf",ans);
    return 0;
}