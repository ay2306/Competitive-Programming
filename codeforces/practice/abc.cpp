#include<bits/stdc++.h>
using namespace std;

string a;

void run(int i, int n){
    if(i == n)cout << a << " ";
    else{
        for(int j = i; j <= n; ++j){
            swap(a[i],a[j]);
            run(i+1,n);
            swap(a[i],a[j]);
        }
    }
}

int main(){
    a = "abc";
    run(0,2);
    return 0;
}