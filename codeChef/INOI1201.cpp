#include <bits/stdc++.h>

using namespace std;

int main(){
    vector<int> vec,veci;
    int n;
    int cont = 0;
    cin >> n;
    for(int i = 0; i < n; ++i){
        int a,b,c;
        cin >> a >> b >> c;
        vec.push_back(a+b+c);
    }
    return 0;
}
