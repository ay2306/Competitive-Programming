#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("input.txt","w",stdout);
    string a = "WWWWWWWWWWWWWWWBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBWWWWWWWWWWWWWWWW";
    for(int i = 0; i < 44; ++i)cout << a << endl;
    for(int i = 0; i < 43; ++i)cout << a << endl;
    for(int i = 0; i < a.length(); ++i)cout << "W";
}