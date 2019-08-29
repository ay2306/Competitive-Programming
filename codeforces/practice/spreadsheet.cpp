/*
 ____________________________________________________________
|                                                            |
|                   Author: ay2306                           |
|____________________________________________________________|

*/
#include <bits/stdc++.h>
#define MOD 1000000007
#define test int t; cin>>t; while(t--)
#define init(arr,val) memset(arr,val,sizeof(arr))
#define loop(i,a,b) for(int i=a;i<b;i++)
#define loopr(i,a,b) for(int i=a;i>=b;i--)
#define loops(i,a,b,step) for(int i=a;i<b;i+=step)
#define looprs(i,a,b,step) for(int i=a;i>=b;i-=step)
#define ull unsigned long long int
#define ll long long int
#define P pair
#define PLL pair<long long, long long>
#define PII pair<int, int>
#define PUU pair<unsigned long long int, unsigned long long int>
#define L list
#define V vector
#define D deque
#define ST set
#define MS multiset
#define M map
#define UM unordered_map
#define mp make_pair
#define pb push_back
#define pf push_front
#define MM multimap
#define F first
#define S second
#define IT iterator
#define RIT reverse_iterator
#define FAST ios_base::sync_with_stdio(false);cin.tie();cout.tie();
#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);
#define MAXN 25
using namespace std;

string fromRC(string s){
    int r = 0;
    int i = 0;
    while(s[i]!='C'){
        if(s[i] >= '0' && s[i] <= '9'){
            int k = s[i]-'0';
            r*=10;
            r+=k;
        }
        ++i;
    }
    // cout << r << " ";
    ++i;
    int c = 0;
    while(i!=s.size()){
        if(s[i] >= '0' && s[i] <= '9'){
            int k = s[i]-'0';
            c*=10;
            c+=k;
        }
        ++i;
    }
    // cout << c << "\n";
    swap(r,c);
    string ans = "";
    while(r){
        char p = char((r%26)+'A'-1);
        int op = r;
        r/=26;
        if(p == '@')r--;
        if(p == '@')p='Z';

        // printf("r = %d, rMOD26 = %d, char level = %c\n",op,op%26,p);
        ans = p + ans;
    }
    string a = "";
    while(c){
        a+=(char(c%10)+'0');
        c/=10;
    }
    reverse(a.begin(),a.end());
    ans+=a;
    return ans;
}

string toRC(string s){
    int i = 0;
    while(s[i]<='Z' && s[i]>='A')++i;
    int k = i;
    i--;
    int c = 0;
    for(int j = 0; i >= 0; ++j){
        c+=(pow(26,j)*(s[i]-'A'+1));
        --i;
    }
    int r = 0;
    string ans = "R";
    while(k < s.size()){
        ans+=s[k++];
    }
    ans+="C";
    string a = "";
    while(c){
        a+=(char(c%10)+'0');
        c/=10;
    }
    reverse(a.begin(),a.end());
    ans+=a;
    return ans;
}

int main(){
    FAST
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int a = 0;
        int n = 0;
        for(auto i : s){
            if(i >= 'A' && i <= 'Z')a++;
            else n++;
        }
        if(a == 2 && !(s[1] >= 'A' && s[1] <= 'Z')){
            cout << fromRC(s) << "\n";
        }else{
            cout << toRC(s) << "\n";
        }
    }
    return 0;
}