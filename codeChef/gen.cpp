#include<bits/stdc++.h>
using namespace std;
char x;
int parseInt(char *a){
    int s = 0;
    for(int i = 0; a[i] != '\0'; ++i)s = s*10 + a[i] - '0';
    return s;
}
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
int getRandom(int l, int r){
    uniform_int_distribution<int> uid(l,r);
    return uid(rng);
}

string randomString(int len){
    string s = "";
    while(len--){
        int op = getRandom(1,4);
        if(op == 1)s+=x;
        else s+=char(getRandom('a','z'));
    }
    return s;
}

int main(int argc, char **argv){
    freopen("input.txt","w",stdout);
    cout << 1 << "\n";
    int l = getRandom(1,50);
    int r = getRandom(l+3,l+10000);
    cout << l << " " << r << "\n";
    return 0;
}