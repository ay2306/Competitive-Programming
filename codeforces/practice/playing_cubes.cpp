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
#define MAXN 25
using namespace std;

PII play(int r, int w,char last){
    // char last = 'r';
    PII ans = mp(0,0);
    int c = 1;
    while(r || w){
        if(last != 'r' && c && r > 0){
            // cout << "1\n";
            last = 'r';
            r--;
            ans.first++;
        }
        else if(last != 'r' && c && r == 0){
            // cout << "2\n";
            last = 'w';
            w--;
            ans.second++;
        }
        else if(last != 'w' && c && w > 0){
            // cout << "3\n";
            last = 'w';
            w--;
            ans.first++;
        }
        else if(last != 'w' && c && w == 0){
            // cout << "4\n";
            last = 'r';
            ans.second++;
            r--;
        }
        
        else if(last != 'w' && !c && r > 0){
            // cout << "5\n";
            last = 'r';
            ans.second++;
            r--;
        }
            // ans.first++;
        else if(last != 'w' && !c && r == 0){
            // cout << "6\n";
            last = 'w';
            ans.first++;
            w--;
        }
        else if(last != 'r' && !c && w > 0){
            // cout << "7\n";
            last = 'w';
            w--;
            ans.second++;
        }
        else if(last != 'r' && !c && w == 0){
            // cout << "8\n";
            last = 'r';
            r--;
            ans.first++;
        }
        c = 1-c;
    }
    return mp(ans.second,ans.first);
}

int main(){
    int r,w;
    cin >> r >> w;
    PII a = play(r-1,w,'r');
    PII b = play(r,w-1,'w');
    // printf("a = %d %d\n",a.first,a.second);
    // printf("a = %d %d\n",b.first,b.second);
    if(a.first > b.first){
        cout << a.first << " " << a.second;
    }else if(b.first > a.first){
        cout << b.first << " " << b.second;
    }else if(a.second < b.second){
        cout << a.first << " " << a.second;
    }else if(a.second > b.second){
        cout << b.first << " " << b.second;
    }else{
        cout << a.first << " " << a.second;
    }
    return 0;
}