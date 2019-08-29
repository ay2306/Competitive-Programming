#include <bits/stdc++.h>
#define ll long long int
#define V vector
#define UM unordered_map
#define mp make_pair
#define pb push_back
#define pf push_front
using namespace std;

string reduce(string a){
    int i = 0;
    string ans = "";
    for(; i < a.size() && a[i] == '0'; ++i);
    if(i == a.size())return "0";
    else{
        for(; i < a.size(); ++i)ans+=a[i];
    }
    return ans;
}

string multBysingleDigit(string a, char b){
    int y = b-'0';
    string ans = "";
    int i = a.size()-1;
    int carry = 0;
    for(; i >= 0; --i){
        int x = (a[i]-'0')*y;
        x+=carry;
        char c = (x%10) + '0';
        ans = c + ans;
        carry = x/10;
    }
    if(carry){
        char d = carry+'0';
        ans = d+ans;
    }
    return reduce(ans);
}

string getadd(string a, string b){
    int c = 0;
    string ans = "";
    int i = a.size() - 1;
    int j = b.size() - 1;
    while(i >= 0 || j >= 0){
        int x = (i >= 0)?(a[i]-'0'):0;
        int y = (j >= 0)?(b[j]-'0'):0;
        x+=(y+c);
        c = x/10;
        char t = '0'+(x%10);
        ans = t+ans;
        i--;
        j--;
    }
    if(c){
        ans = "1"+ans;
    }
    return ans;
}

string sub(string a, string b){
    int c = 0;
    string ans = "";
    int i = a.size() - 1;
    int j = b.size() - 1;
    while(i >= 0 || j >= 0){
        int x = (i >= 0)?(a[i]-'0'):0;
        int y = (j >= 0)?(b[j]-'0'):0;
        x-=c;
        c = 0;
        if(x < y){
            x+=10;
            c = 1;
        }
        x-=(y);
        char t = '0'+(x%10);
        ans = t+ans;
        i--;
        j--;
    }
    return (reduce(ans));

}

string mult(string a, string b){
    int j;
    int max_size = 0;
    int i;
    V<string> ans;
    ans.pb(a);
    ans.pb("*" + b);
    string dashes = "";
    string tt = multBysingleDigit(a,b[b.size()-1]);
    for(i = 0; i < max(b.size()+1,tt.size()); ++i)dashes+="-";
    ans.pb(dashes);
    ans.push_back(tt);
    string spaces = " ";
    if(b.size() == 1){
        for(auto k: ans)max_size = max(max_size,int(k.size()));
        V<V<char> > result (ans.size(),V<char>(max_size,' '));
        for(i = 0; i < ans.size(); ++i){
            j = max_size - 1;
            for(auto itr = ans[i].rbegin(); itr != ans[i].rend(); --j,++itr){
                result[i][j]=*itr;
            }
        }
        string ret = "";
        for(int i = 0; i < result[result.size()-1].size(); ++i){
            if(result[result.size()-1][i] >= '0' && result[result.size()-1][i] <= '9')ret += result[result.size()-1][i];
        }
    }
    return reduce(ret);
    for(i = b.size()-2; i >= 0; --i){
        string val = multBysingleDigit(a,b[i]);
        val+=spaces;
        spaces+=" ";
        ans.pb(val);
    }
    i = ans.size()-1;
    string res = "0";
    for(; i > 2; --i){
        string b = ans[i];
        for(int j = b.size()-1; j >= 0 && b[j] == ' '; --j){
            b[j] = '0';
        }
        res = getadd(res,b);
    }
    max_size = res.size();
    dashes = "";
    for(int i = 0; i < max_size; ++i)dashes+="-";
    ans.pb(dashes);
    ans.pb(res);
    for(auto i: ans)max_size = max(max_size,int(i.size()));
    V<V<char> > result (ans.size(),V<char>(max_size,' '));
    for(i = 0; i < ans.size(); ++i){
        j = max_size - 1;
        for(auto itr = ans[i].rbegin(); itr != ans[i].rend(); --j,++itr){
            result[i][j]=*itr;
        }
    }
    string ret = "";
    for(int i = 0; i < result[result.size()-1].size(); ++i){
        if(result[result.size()-1][i] >= '0' && result[result.size()-1][i] <= '9')ret += result[result.size()-1][i];
    }
    return reduce(ret);
}

void solve(){
    int n;
    cin >> n;
    string k = "";
    while(n){
        char c = n%10 + '0';
        n/=10;
        k+=c;
    }
    string ans = "1";
    reverse(k.begin(),k.end());
    while(k != "1" && k != "0"){
        ans = mult(ans,k);
        k = sub(k,"1");
    }
}

int main(){
    // FILE_READ_IN
    // FILE_READ_OUT
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}