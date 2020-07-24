#include<bits/stdc++.h>
using namespace std;
int s[100100];
int main(){
    int n,a,k,mni=0;
    cin >> n >> k;
    for(int i = 0; i < n; ++i){
        cin >> a;
        s[i%k]+=a;
    }
    for(int i = 1; i < k; ++i)
        if(s[i] < s[mni])mni=i;
    return cout << mni+1 , 0;
}