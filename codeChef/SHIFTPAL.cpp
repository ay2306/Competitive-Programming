#include<iostream>
#include<vector>
#define ll unsigned long long int
using namespace std;
ll fact(int a){
    ll i = a;
    a--;
    while(a > 1){
        i*=a;
        a--;
    }
return i;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        string a;
        cin >> a;
        int f[26] = {0};
        for(int i = 0; i < a.length(); ++i){
            f[a[i]-97]++;
        }
        int pos = true;
        if(a.lenght()%2 == 0){
            for(int i = 0; i < 26; ++i){
                if(f[i]%2 == 1){pos = false;break;}
            }
        }
        if(a.length()%2 == 1){
            bool tmp = true;
            for(int i = 0; i < 26; ++i){
                if(f[i]%2 == 1){
                    if(tmp)tmp = false;
                    else{
                        pos = false;
                        break;
                    }
                }
            }
        }
        vector<ll>denom;
        if(pos){
            ll sum = 0;
            for(int i = 0; i < 26; ++i){
                if(f[i]!=0)sum+=(f[i]/2);
                denom.push_back(fact(f[i]/2));
            }
        }
        prod
    }
    return 0;
}