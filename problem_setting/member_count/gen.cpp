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
        int n = getRandom(n_low,n_high);
        int yes = getRandom(0,1);
        if(yes){
            int k = getRandom(2,sqrt(max(2,n)));
            k*=(k-1);
            k/=2;
            cout << k << "\n";
        }else{
            int k = getRandom(1,n);
            cout << k << "\n";
        }
    }
    return 0;
}