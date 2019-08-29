#include<bits/stdc++.h>
using namespace std;

long long int arr[100010];

string stOI(int a){
    string ans = "";
    while(a){
        ans+=char(a%10+'0');
        a/=10;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int main(){
    for(int k = 2; k <=94; ++k){
        string path = "input" + stOI(k) + ".txt";
        string opath = "output" + stOI(k) + ".txt";
        char *in = new char[path.length()+10];
        char *out = new char[opath.length()+10];
        for(int i = 0; i < path.length(); ++i){
            in[i] = path[i];
        }
        in[path.length()] = '\0';
        for(int i = 0; i < opath.length(); ++i){
            out[i] = opath[i];
        }
        out[opath.length()] = '\0';
        freopen(in,"r",stdin);
        freopen(out,"w",stdout);
        int n;
        long long int x;
        cin >> n >> x;
        for(int i = 0; i < n; ++i){cin >> arr[i];arr[i]-=x;}
        const long long int zero = 0;
        long long int max_so_far = 0;
        long long int max_ending_here = 0;
        for(int i = 0; i < n; ++i){
            max_ending_here += arr[i];
            max_ending_here = max(max_ending_here,zero);
            max_so_far = max(max_ending_here,max_so_far);
        }
        cout << x + max_so_far;

    }
    return 0;
}