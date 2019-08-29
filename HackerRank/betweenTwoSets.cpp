#include<bits/stdc++.h>

using namespace std;

int gcd(int a, int b){
    if(b==0)return a;
    return gcd(b,a%b);
}

int main(){
    int n,m;
    cin >> n >> m;
    int hcf_a,lcm_a,a;
    int hcf_b,lcm_b,b;
    int min_b = 1000;
    cin >> a;
    lcm_a = a;
    hcf_a = a;
    for(int i = 1; i < n; ++i){
        cin >> a;
        hcf_a = gcd(a,lcm_a);
        lcm_a = (a*lcm_a)/hcf_a;
    }
    cin >> b;
    if(min_b > b)min_b = b;
    lcm_b = b;
    hcf_b = b;
    for(int i = 1; i < m; ++i){
        cin >> b;
        if(min_b > b)min_b = b;
        hcf_b = gcd(b,lcm_b);
        lcm_b = (a*lcm_b)/hcf_b;
    }
    int k = gcd(lcm_a,hcf_b);
    k = (lcm_a*hcf_b)/k;
    int cnt = 0;
    while(k<=min_b){
//        cout << k << " ";
        cnt++;
        if(hcf_a!=1){k*=hcf_a;}
        else{k++;}
    }
    cout  << cnt;
}
