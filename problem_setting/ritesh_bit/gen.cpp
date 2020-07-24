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
    if(argc > 5){
        test = 2;
    }
    cout << test << "\n";
    int n_low = parseInt(argv[1]);
    int n_high = parseInt(argv[2]);
    int q_low = parseInt(argv[3]);
    int q_high = parseInt(argv[4]);
    while(test--){
        int n = getRandom(n_low,n_high);
        int x = getRandom(1,n_high);
        cout << n << " " << x << "\n";
        while(n--){
            cout << getRandom(q_low,q_high) << " ";
        }
        cout << "\n";
    }

    return 0;
}