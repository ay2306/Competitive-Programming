#include<bits/stdc++.h>
using namespace std;
int N;
struct segment{
    vector<int> a;
    segment():a(N+10){}
    segment operator+(const segment &r){
        segment k;
        for(int i = 1 ; i <= N; ++i)k.a[i] = a[i] + r.a[i];
        return k;
    }
    segment operator-(const segment &r){
        segment k;
        for(int i = 1 ; i <= N; ++i)k.a[i] = a[i] - r.a[i];
        return k;
    }
    void print(){
        int p = 0;
        cout << "( ";
        for(int i = 1 ; i <= N; ++i){
            if(a[i] == 0)continue;
            if(a[i] < 0)cout << " - " << abs(a[i]) << " a" << i , p++;
            else{
                if(p)cout << " + ";
                cout << abs(a[i]) << " a" << i;
                p++;
            }
        }
        cout << " ) ";
    }
};

int main(){
    int sz ;
    cin >> sz;
    N = sz;
    vector<segment> a(sz+1);
    for(int i = 1; i <= sz; ++i){
        a[i].a[i] = 1;
    }
    int op = 1;
    for(int s = 1; s <= sz; ++s){
        for(int i = 1; i <= sz-s+1; ++i)a[i].print();
        for(int i = 1; i <= sz-s; ++i){
            // cout << i << "\n";
            if(op)a[i] = a[i] + a[i+1];
            else a[i] = a[i] - a[i+1];
            op^=1;
        }
        cout << endl;   
    }
    return 0;
}