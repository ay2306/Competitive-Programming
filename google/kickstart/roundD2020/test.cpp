#include<bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

int getRandom(int l, int r){
    uniform_int_distribution<int> uid(l,r);
    return uid(rng);
}

vector<int> getArray(int n, int l = 0, int r = INT_MAX){
    vector<int> a;
    while(a.size() < n)a.emplace_back(getRandom(l,r));
    return a;
}

int main(){
    freopen("inp.txt","w",stdout);
    int n = getRandom(5,10);
    auto a = getArray(n,1,50);
    cout << 1 << "\n" << n << "\n";
    for(int i: a)cout << i << " ";
    return 0;
}