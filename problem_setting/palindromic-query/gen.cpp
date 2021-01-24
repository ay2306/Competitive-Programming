#include<bits/stdc++.h>
#define int long long
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int getRandom(int l, int r){
    uniform_int_distribution<int> uid(l,r);
    return uid(rng);
}
int parseInt(char *a){
    int s = 0;
    for(int i = 0; a[i] != '\0'; ++i)s = s*10 + a[i] - '0';
    return s;
}

string getstring(int len){
    string ans = "";
    while(len--){
        ans+=char(getRandom('a','z'));
    }
    return ans;
}

string getPalindrome(int len){
    int k = (len+1)/2;
    string a = getstring(k);
    string b = a;
    if(len&1)b.pop_back();
    reverse(b.begin(),b.end());
    return a+b;
}


int32_t main(int argc, char **argv){
    freopen("input.txt","w",stdout);
    int n_low = parseInt(argv[1]);
    int n_high = parseInt(argv[2]);
    int n = getRandom(n_low,n_high);
    int q = getRandom(n_low,n_high);
    if(n <= 20)q = getRandom(2,5);
    vector<pair<int,int>> qt;
    if(n >= 10101){
        string s = getPalindrome(n);
        for(int i = 1, j = n; i <= j; ++i,j--){
            qt.emplace_back(i,j);
        }
        cout << n << " " << q << "\n";
        cout << s << '\n';
        while(q--){
            if(getRandom(1,2) == 1 && qt.size()){
                cout << qt.back().first << " " << qt.back().second << "\n";
                qt.pop_back();
            }else{
                int l = getRandom(1,n-1);
                int r = getRandom(l,n);
                cout << l << " " << r << "\n";
            }
        }
        return 0;
    }
    cout << n << " " << q << "\n";
    string ans = "";
    while(ans.size() < n){
        int l = ans.size()+1;
        ans += getPalindrome(getRandom(1,n-ans.size()));
        int r = ans.size();
        qt.emplace_back(l,r);
    }
    cout << ans << "\n";
    while(q--){
        if(getRandom(1,2) == 1 && qt.size()){
            cout << qt.back().first << " " << qt.back().second << "\n";
            qt.pop_back();
        }else{
            int l = getRandom(1,n-1);
            int r = getRandom(l,n);
            cout << l << " " << r << "\n";
        }
    }
    return 0;
}
