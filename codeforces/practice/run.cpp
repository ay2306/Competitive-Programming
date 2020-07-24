#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a;
    for(int i = 1; i <= n; ++i)a.emplace_back(i);
    do{
        set<int> s;
        int p = 1;
        for(int i : a){
            p = p * i % n;
            s.emplace(p);
        }
        if(s.size() != n)continue;
        for(int i : a)cout << i << " ";
        cout << "\n";
    }while(next_permutation(a.begin(),a.end()));
}