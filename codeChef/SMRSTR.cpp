#include<iostream>

using namespace std;

inline int getnum(){
    int t = 0;
    char c = getchar_unlocked();
    while(c>=48 && c<=57){
        t = (t<<3)+(t<<1)+(c-48);
        c = getchar_unlocked();
    }
    return t;
}

int main(int argc, char const *argv[]){
    int t;
    t = getnum();
    while(t--){
        int n,q,k;
        n = getnum();
        q = getnum();
        long long prod[100000] = {0};
        int j = 0;
        for(int i = 0; i < n; ++i){
            if(prod[j]==0)prod[j]=1;
            k = getnum();
            prod[j]*=k;
            if(prod[j]>10000000 && ((i+1) < n))++j;
        }
        for(int i = 0; i < q; ++i){
            k = getnum();
            for(int a = 0; a <= j; ++a){
                k/=prod[a];
                if(k==0)break;
            }
            cout << k << " ";
        }
        cout << "\n";
    }
return 0;
}

