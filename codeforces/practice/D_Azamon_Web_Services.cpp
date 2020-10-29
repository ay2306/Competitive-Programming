#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    while(n--){
        string a,b;
        cin >> a >> b;
        map<char,int> m;
        for(int i = 0; i < a.size(); ++i){
            m[a[i]] = i;
        }
        bool done = 
        for(int i = 0; i < b.size(); ++i){
            for(char c = 'A'; c < b[i]; ++c){
                if(m[c] != 0){
                    swap(a[])
                }
            }
        }
    }
    return 0;
}