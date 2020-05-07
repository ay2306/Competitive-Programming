//https://codeforces.com/contest/7/problem/B
#include<bits/stdc++.h>
using namespace std;
string s;
int memory[100],lim,id,q;
void allocate(){
    int sz;
    cin >> sz;
    for(int i = 0; i < lim && sz > 0; ++i){
        if(memory[i] == 0){
            if(i+sz-1 >= lim){
                cout << "NULL\n";
                return;
            }
            int s = 0;
            for(int j = 0; j < sz; ++j)s+=memory[i+j];
            if(s == 0){
                // cout << "STARTING AT i == " << i << "\n";
                for(int j = 0; j < sz; ++j)memory[i+j] = id+1;
                cout << ++id << "\n";
                return;
            }
        }
    }
    cout << "NULL\n";
    return;
}

void defragment(){
    int l = 0;
    for(int i = 0; i < lim; ++i){
        if(memory[i])swap(memory[l++],memory[i]);
    }
}

void erase(){
    int id;
    cin >> id;
    for(int i = 0; i < lim && id > 0; ++i){
        if(memory[i] == id){
            while(i < lim && memory[i] == id)memory[i++]=0;
            return;
        }
    }
    cout << "ILLEGAL_ERASE_ARGUMENT\n";
}

int main(){
    cin >> q >> lim;
    while(q--){
        cin >> s;
        if(s == "defragment")defragment();
        if(s == "erase")erase();
        if(s == "alloc")allocate();
    }
    return 0;
}