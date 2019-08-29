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
#define S set
#define MS multiset
#define M map
#define mp make_pair
#define pb push_back
#define MM multimap
#define IT iterator
#define RIT reverse_iterator
#define FAST ios_base::sync_with_stdio(false);cin.tie();cout.tie();

using namespace std;

string f(int a, int b, int x){
    int i;
    // cin>>a>>b>>x;

    string s="";
    for(i=0;i<a;i++)
    {
    s+="0";
    }
    //cout<<s;
    string str1="1";

    int j=1;
    while(x>=2)
    {
    if(x>=2)
    {


    if(j==s.length())
    x-=1;
    else
    x-=2;
    s.insert(j,str1);
    b--;
    }
    j+=2;

    }
    //cout<<"\n";
    //cout<<s;
    int p=0;
    while(b>0&&x>0)
    {
    s.insert(p,str1);
    b--;
    }

    for(i=0;i<s.length();i++)
    {
    if(s[i]=='1')
    {
    while(b>0)
    {
        s.insert(i,str1);
        b--;
    }

    }
    if(b<=0)
    break;

    }

    return s;
}

int main(){
    freopen("input.txt","r",stdin);
    int a,b,x,z=0,o=0,c=0;
    cin >> a >> b >> x;
    string s=f(a,b,x);
    // string s = "";
    // if(a > b){
    //     s+="0";
    //     z++;
    //     for(c = 1; c+1 <= x; ++c){
    //         s+=('1' + '0' - s[c-1]);
    //         if(s[c]=='0')z++;
    //         else o++;
    //     }
    //     c--;
    //     if(s[c] == '0'){
    //         for(; z < a; ++z)s+="0";
    //         for(; o < b; ++o)s+="1";
            
    //     }
    //     if(s[c] == '1'){
    //         for(; o < b; ++o)s+="1";
    //         for(; z < a; ++z)s+="0";
            
    //     }
    // }
    // else{
    //     s+="1";
    //     o++;
    //     for(c = 1; c+1 <= x; ++c){
    //         s+=('1' + '0' - s[c-1]);
    //         if(s[c]=='0')z++;
    //         else o++;
    //     }
    //     c--;
    //     // cout << s[c] << endl;
    //     if(s[c] == '0'){
    //         // cout  << z << " " << o << endl;
    //         for(; z < a; ++z)s+="0";
    //         for(; o < b; ++o)s+="1";
            
    //     }
    //     if(s[c] == '1'){
    //         // cout  << z << " " << o << endl;
    //         for(; o < b; ++o)s+="1";
    //         for(; z < a; ++z)s+="0";
            
    //     }
    // }
    c=0;
    for(int i = 0; i+1 < s.length(); ++i){
        if(s[i]!=s[i+1])c++;
    }
    cout << endl;
    cout << a << " " << b << " "<<  c << " " << x;
    cout << endl;
    if(c!=x){
        cout << "PROBLEM\n";
    }
    cout << s;
    return 0;
}