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
    int x_low = 1;
    int x_high = 100000/2;

    if(n_high <= 20)test = 2,x_high = 30;
    cout << test << "\n";
    while(test--){
        int n = getRandom(n_low,n_high);
        if(n > 10000)assert(false);
        vector<int> arr(n);
        int mn = INT_MAX;
        int mx = INT_MIN;
        for(int &i: arr)i = getRandom(x_low,x_high);
        for(int &i: arr)
            mn = min(i,mn), mx = max(mx,i);
        int yes = getRandom(0,1);
        int x;
        if(!yes)x = getRandom(mx+1,max(mx+1,x_high));
        else x = getRandom(mn,mx);
        cout << n << " " << x << "\n";
        for(int i: arr)cout << i << " ";
        cout << endl;
    }
    return 0;
}