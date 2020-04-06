#include<bits/stdc++.h>
using namespace std;
int a[110], ans[110],t,b,val,steps,actual_steps,nxt,p;
bool comp,inv;
inline int r(int x){return b+1-x;}

void make_changes(int ind){
    comp = false, inv = false, p = 0;
    actual_steps+=2;
    for(int i = 1; i <= b; i++)ans[i]=a[i];
    for(int i = 1; i <= ind; i++){
        if(a[r(i)] == a[i]){
            cout << i << endl;
            cin >> val;
            if(val != a[i])comp=true;
            p++;
            break;
        }
    }
    if(comp)for(int i = 1; i <= ind; i++)ans[i]=1-ans[i],ans[b+1-i]=1-ans[b+1-i];
    for(int i = 1; i <= b; i++){
        if(a[r(i)] != a[i]){
            cout << i << endl;
            cin >> val;
            p++;
            if(!(val == a[i] ^ comp))inv = true;
            break;
        }
    }
    if(inv)for(int i = 1; i <= ind && i <= b+1-i ; i++)swap(ans[i],ans[r(i)]);
    for(int i = 1; i <= ind; i++)a[i] = ans[i],a[r(i)] = ans[r(i)];
    while(p < 2){
        cout << 1 << endl;
        cin >> val;
        p++;
    }
}
void getInputInRange(int k){
    steps+=2;
    actual_steps+=2;
    cout << k << endl;
    cin >> val;
    a[k] = val;
    cout << b+1-k << endl;
    cin >> val;
    a[r(k)] = val;
}

int main(){
    cin >> t >> b;
    while(t--){
        for(int i = 1; i <= b;++i)a[i] = 1;
        steps = 0, actual_steps = 0,nxt = 1;
        while(nxt <= (b+1)/2){
            if(actual_steps%10 == 0 && actual_steps > 0)make_changes(steps/2);
            else getInputInRange(nxt++);
        }
        for(int i = 1; i <= b; ++i){
            cout << a[i] ;
        }
        cout << endl;
        char j;
        cin >> j;
        if(j == 'N'){
            exit(0);
        }
    }
    return 0;
}