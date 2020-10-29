#include<bits/stdc++.h>
using namespace std;

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

int main(int argc, char **argv){
    freopen("input.txt","w",stdout);
    int test = getRandom(1,100);
    int n_low = parseInt(argv[1]);
    int n_high = parseInt(argv[2]);
    if(n_high <= 100)test = 5;
    if(n_high <= 20)test = 2;
    cout << test << "\n";
    while(test--){
        int h1,h2,m1,m2; 
        do{
            h2 = getRandom(0,23);
            h1 = getRandom(0,23);
            m2 = getRandom(0,59);
            m1 = getRandom(0,59);
        }while(h1 == h2 && m1 == m2);
        string a = "";
        if(h1 < 10)a+="0";
        a+=to_string(h1);
        a+=":";
        if(m1 < 10)a+="0";
        a+=to_string(m1);
        cout << a << "\n";
        a = "";
        if(h2 < 10)a+="0";
        a+=to_string(h2);
        a+=":";
        if(m2 < 10)a+="0";
        a+=to_string(m2);
        cout << a << "\n";
    }
    return 0;
}