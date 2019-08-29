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
#define FILE_READ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
using namespace std;

int main(){
    int m,s;
    cin >> s >> m;
    // cout << s*9 << " " << m << endl;
    if(m == 0 && s == 1){
        for(int i = 0; i < s; ++i)cout << "0";
        cout << " ";
        for(int i = 0; i < s; ++i)cout << "0";
        return 0;
    }

    if(s*9 < m || m == 0){
        cout << "-1 -1";
        return 0;
    }
    if(s == 1){
        cout << m << " " << m;
        return 0;
    }
    if(m == 1 && m != s){
        cout << "1";
        for(int i = 1; i < s; ++i)cout << "0";
        cout << " ";
        cout << "1";
        for(int i = 1; i < s; ++i)cout << "0";
        return 0;
    }
    // if(m == 2){
    //     cout << "1";
    //     for(int i = 2; i < s; ++i)cout << "0";
    //     cout << "1 ";
    //     cout << "1";
    //     for(int i = 2; i < s; ++i)cout << "0";
    //     cout << "1";
    //     return 0;
    // }
    if(s*9 == m){
        for(int i = 0; i < s; ++i)cout << "9";
        cout << " ";
        for(int i = 0; i < s; ++i)cout << "9";
        return 0;
    }
    int t = m;
    char *mn = new char[s+1];
    char *mx = new char[s+1];
    mn[s] = '\0';
    mx[s] = '\0';
    int i = s-1;
    while(t > 9 && i >= 0){
        mn[i] = '9';
        i--;
        t-=9;
    }
    if(t && i!=0){mn[i] = char((t-1)+'0');t=1;--i;}
    while(i > 0){
        mn[i] = '0';
        --i;
    }
    if(t>0)mn[0]=char(t+'0');
    i = 0;
    t = m;
    while(t > 9 && i < s){
        mx[i] = '9';
        i++;
        t-=9;
    }
    if(i!=s){mx[i] = char(t+'0'); t = 0; ++i;}
    // if(t && i!=s-1){mx[i] = char((t-1)+'0');t=1;++i;}
    // cout << "MN i" << i << endl;
    while(i <= s-1){
        mx[i] = '0';
        ++i;
    }
    if(t>0)mx[s-1]=char(t+'0');
    cout << mn << " " << mx;
    return 0;
}