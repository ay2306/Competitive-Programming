//https://codeforces.com/contest/1313/problem/C2
#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+10;

int read(){
    int x; char c = 'a';
    while((c = getchar()) < '0' || c > '9');
    for(x = c-'0'; (c = getchar()) >= '0' && c <= '9';)x=x*10+c-'0';
    return x; 
}

void out(int x, int end = ' '){
    if(x == 0 && end != '-')putchar(x);
    if(!x)return;
    out(x/10,'-');
    putchar(char(x%10+'0'));
    if(end != '-')putchar(end);
}

typedef long long int ll;
int n,arr[N],L[N],R[N];
ll dp1[N],dp2[N];

int main(){
    n = read();
    for(int i = 1; i <= n; ++i)arr[i] = read();
    if(n <= 2){
        for(int i = 1; i <= n; ++i)out(arr[i]);
        return 0;
    }
    stack<long long> s;
    for(int i = n; i > 0; --i){
        while(s.size() && arr[s.top()] >= arr[i]){
            L[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }
    while(s.size())s.pop();
    for(int i = 1; i <= n; ++i){
        dp1[i] = dp1[L[i]] + (i-L[i])*1LL*arr[i];
    }
    reverse(arr+1,arr+n+1);
    for(int i = n; i > 0; --i){
        while(s.size() && arr[s.top()] > arr[i]){
            R[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }
    for(int i = 1; i <= n; ++i){
        dp2[i] = dp2[R[i]] + (i-R[i])*1LL*arr[i];
    }
    reverse(dp2+1,dp2+n+1);
    reverse(arr+1,arr+n+1);
    long long mx = 0 ,ind = 0;
    for(int i = 1; i <= n; ++i){
        if(dp1[i] + dp2[i] - arr[i] > mx)ind = i, mx = dp1[i]+dp2[i] - arr[i];   
    }
    for(int i = ind - 1; i > 0; --i)arr[i] = min(arr[i],arr[i+1]);
    for(int i = ind + 1; i <= n; ++i)arr[i] = min(arr[i],arr[i-1]);
    for(int i = 1; i <= n; ++i)
        out(arr[i]);
    return 0;
}


var x = document.getElementsByClassName('ad-banner'); for (var i = 0; i < x.length; ++i)x[i].style.display='none'