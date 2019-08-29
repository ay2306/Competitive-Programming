    #include<bits/stdc++.h>
    #define ll unsigned long long int
    using namespace std;

    int main(){
        int t;
        cin >> t;
        while(t--){
            int n;
            cin >> n;
            ll a;
            set<ll> s[10000];
            ll j = 0;
            while(n--){
                cin >> a;
                if(binary_search(s[a%10000].begin(),s[a%10000].end(),a)){
                    j++;
                }else{
                    s[a%10000].insert(a);
                }
            }
            cout << j << endl;
        }
    }