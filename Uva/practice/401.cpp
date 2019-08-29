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
#define FILE_READ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define MAXN 1001000
using namespace std;
int main(){
    // FILE_READ
    unordered_map<char,char> m;
    for(int i = 2; i < 250; ++i){
        m[char(i)] = '?';
    }
    m['A'] = 'A';
    m['E'] = '3';
    m['H'] = 'H';   
    m['I'] = 'I';   
    m['J'] = 'L';   
    m['L'] = 'J';   
    m['M'] = 'M';   
    m['O'] = 'O';   
    m['S'] = '2';   
    m['T'] = 'T';   
    m['U'] = 'U';   
    m['V'] = 'V';   
    m['W'] = 'W';   
    m['X'] = 'X';   
    m['Y'] = 'Y';   
    m['Z'] = '5';   
    m['1'] = '1';   
    m['2'] = 'S';   
    m['3'] = 'E';   
    m['5'] = 'Z';   
    m['8'] = '8';   
    string a;
    cin >> a;
    while(1){
        int j = a.length()-1;
        int i = 0;
        bool mir = true;
        bool pal = true;
        while(i <= j){
            // cout << a[i] << " " << a[j] << endl;
            // cout << m[a[i]] << " " << m[a[j]] << endl;
            if(a[i] != a[j])pal = false;
            if(a[i] != m[a[j]])mir = false;
            i++;
            j--;
        }
        if(mir && pal){
            cout <<  a << " -- is a mirrored palindrome.\n";
        }
        else if(mir){
            cout <<  a << " -- is a mirrored string.\n";
        }
        else if(pal){
            cout <<  a << " -- is a regular palindrome.\n";
        }
        else{
            cout <<  a << " -- is not a palindrome.\n";
        }
        cout << "\n";
        if(cin >> a){
        }else{
            break;
        }
    }
    return 0;
}