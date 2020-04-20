//https://codeforces.com/problemset/problem/582/B
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 1e5+10;
int n,t,ans,a[110];
int m[110][110],arr[110][110];
const int inf = 1e9;
void mult(int x[110][110], int y[110][110]){
    int z[110][110];
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            z[i][j] = -inf;
            for(int k = 0; k < n; ++k)z[i][j]=max(z[i][j],x[i][k]+y[k][j]);
        }
    }
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            x[i][j] = z[i][j];
        }
    }
}

void power(int x[110][110], int k){
    if(k == 0)return;
    if(k == 1)return ;
    power(x,k>>1);
    mult(x,x);
    if(k&1)mult(x,m);
}

int main(){
    scanf("%d%d",&n,&t);
    for(int i = 0; i < n; ++i)scanf("%d",a+i);
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            if(a[i] > a[j])m[i][j] = -inf;
            else{
                m[i][j] = 1;
                for(int k = 0; k < j; ++k){
                    if(a[k] <= a[j])m[i][j] = max(m[i][j],m[i][k]+1);
                }
            }
            arr[i][j] = m[i][j];
        }
    }
    #ifdef LOCAL
    cout << "XXXXXXXXXXXXXXXXXXXXXXXXX\n";
    for(int i = 0; i < n ; ++i){
        for(int j = 0; j < n; ++j)cout << arr[i][j] << " ";
        cout << endl;
    }
    #endif
    power(arr,t);
    #ifdef LOCAL
    cout << "XXXXXXXXXXXXXXXXXXXXXXXXX\n";
    for(int i = 0; i < n ; ++i){
        for(int j = 0; j < n; ++j)cout << arr[i][j] << " ";
        cout << endl;
    }
    #endif
    #ifndef LOCAL
    for(int i = 0; i < n; ++i)for(int j = 0; j < n; ++j)ans=max(ans,arr[i][j]);
    printf("%d",ans);
    #endif
    return 0;
}