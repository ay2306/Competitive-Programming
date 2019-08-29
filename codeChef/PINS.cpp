#include<bits/stdc++.h>
using namespace std;

bool pal(string a){
    int i = 0;
    int j = a.length()-1;
    while(i < j){
        if(a[i] != a[j])return false;
        ++i;
        --j;
    }
    cout << a << endl;
    return true;
}

int test(){
    freopen("input.txt","r",stdin);
    int n;
    cin >> n;
    int c = 0;
    string a;
    for(int i = 0; i < n; ++i){
        cin >> a;
        if(pal(a))c++;
    }
    cout << c << endl;    
}

void solve(int n){
    if(n == 1){
        cout << "1 1" << endl;
        return ;
    }
    cout << "1 1";
    if(n%2 == 0)for(int i = 0; i < n/2; ++i)cout << "0";
    else for(int i = 0; i < (n-1)/2; ++i)cout << "0";
    cout << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        solve(n);
    }
    // test();
}