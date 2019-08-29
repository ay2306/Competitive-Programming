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

int d2i(char a){
    switch(a){
        case 'N': return 1;
        case 'E': return 2;
        case 'S': return 4;
        case 'W': return 8;
    }
}

int main(){
    int n,m;
    map<pair<int,int>,int> lost;
    // FILE_READ
    cin >> n >> m;
    int x,y,lst;
    char d,ld;
    cin >> x >> y >> d;
    ld = d;
    while(1){
        lst = 0;
        string a;
        cin >> a;
        for(auto i: a){
            if(!lst){
                if(i == 'R'){
                    if(d == 'N')d='E';
                    else if(d == 'E')d='S';
                    else if(d == 'S')d='W';
                    else if(d == 'W')d='N';
                    ld = d;
                }
                else if(i == 'L'){
                    if(d == 'N')d='W';
                    else if(d == 'E')d='N';
                    else if(d == 'S')d='E';
                    else if(d == 'W')d='S';
                    ld = d;
                }
                else if(i == 'F'){
                    switch(d){
                        case 'N': y++;
                                  break;
                        case 'S': y--;
                                  break;
                        case 'E': x++;
                                  break;
                        case 'W': x--;
                                  break;
                    }
                }
                if(x < 0 || x > n){
                    switch(d){
                        case 'E': x--;
                                  break;
                        case 'W': x++;
                                  break;
                    }
                    if(lost.find(mp(x,y)) == lost.end()){
                        lost[mp(x,y)] = d2i(d);
                        lst = 1;
                        break;
                    }else if(!(lost[mp(x,y)] & d2i(d))){
                        lost[mp(x,y)] += d2i(d);
                        lst = 1;
                    }
                }
                if(y < 0 || y > m){
                    switch(d){
                        case 'N': y--;
                                  break;
                        case 'S': y++;
                                  break;
                    }
                    if(lost.find(mp(x,y)) == lost.end()){
                        lost[mp(x,y)] = d2i(d);
                        lst = 1;
                        break;
                    }else if(!(lost[mp(x,y)] & d2i(d))){
                        lost[mp(x,y)] += d2i(d);
                        lst = 1;
                    }
                }
            }
        }
        cout << x << " " << y << " " << ld;
        if(lst == 1){
            cout << " " << "LOST";
        }
        cout << "\n";
        if(cin >> x >> y >> d){

        }else{
            break;
        }
    }
    return 0;
}
