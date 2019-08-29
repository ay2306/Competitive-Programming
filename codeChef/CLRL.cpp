#include<bits/stdc++.h>
using namespace std;

int main(){
int t;
cin >> t;
int a,b;
while(t--){
    set<int> s;
    bool c = true;
    cin >> a >> b;
    int q,k=a;
    int mini,maxi;
    maxi = b;
    mini = 0;
    cin >> k;
    q = k;
    s.insert(k);
    while(q!=b){
        cin >> q;
        if(c){
            if(q > k && b < k){
            //cout << "K: " << k << "\tQ: " << q << "\n";
            c = false;
            k = q;
            continue;
            }

            if(q < k && b > k){
            //cout << "K: " << k << "\tQ: " << q << "\n";
                c = false;
                k = q;
                continue;
            }
            if(q>k){
                //cout << "Q > K\n";
                set<int>::iterator itr = s.find(k);
                ++itr;
                if(*itr < q && *itr!=k){
                    //cout << "K: " << k << "\tQ: " << q << "\t*itr: " << *itr << "\n";
                    c=false;
                }
            }

            if(q<k){
                //cout << "Q < K\n";
                set<int>::iterator itr = s.find(k);
                --itr;
                if(*itr > q && *itr!=k){
                    //cout << "K: " << k << "\tQ: " << q << "\t*itr: " << *itr << "\n";
                    c=false;
                }

            }
        k = q;
        s.insert(k);
    }
    }
    if(c)cout << "YES\n";
    if(!c)cout << "NO\n";
}

return 0;
}
