//https://codeforces.com/problemset/problem/10/D
#include<bits/stdc++.h>
using namespace std;

vector<int> a,b,c,prv,res;
int n,m;

int main(){
    scanf("%d",&n);
    a.resize(n);
    for(int &i: a)scanf("%d",&i);
    scanf("%d",&m);
    b.resize(m);
    for(int &i: b)scanf("%d",&i);
    c.resize(m,0),prv.resize(m,0);
    for(int i = 0; i < n; ++i){
        int cur = 0, last = -1;
        for(int j = 0; j < m; ++j){
            if(a[i] == b[j] && cur+1 > c[j]){
                c[j] = cur+1;
                prv[j] = last;
            }
            if(b[j] < a[i] && cur < c[j]){
                cur = c[j];
                last = j;
            }
        }
    }
    int index = max_element(c.begin(),c.end())-c.begin();
    if(!c[index])return printf("0\n"),0;
    printf("%d\n",c[index]);
    while(~index){
        res.emplace_back(index);
        index = prv[index];
    }
    for(auto i = res.rbegin(); i != res.rend(); ++i)printf("%d ",b[*i]);
    return 0;
}