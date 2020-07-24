//https://codeforces.com/contest/286/problem/C
#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
map<int,set<int>> m;
int arr[N], fix[N];

int main(){
    int a,n,d;
    scanf("%d",&n);
    for(int i = 1; i <= n; ++i){
        scanf("%d",arr+i);
    }
    reverse(arr+1,arr+n+1);
    scanf("%d",&d);
    while(d--){
        scanf("%d",&a);
        arr[n-a+1] = -arr[n-a+1];
    }
    stack<int> s;
    for(int i = 1; i <= n; ++i){
        if(arr[i] > 0 && s.size() && arr[s.top()] == -arr[i])s.pop();
        else{
            s.push(i);
            arr[i] = -abs(arr[i]);
        }
    }
    if(s.size())return printf("NO"),0;
    printf("YES\n");
    reverse(arr+1,arr+n+1);
    for(int i = 1; i <= n; ++i)printf("%d ",arr[i]);
    return 0;
}