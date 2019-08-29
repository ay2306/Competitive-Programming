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

int st = 0;

void fastscan(int &number) 
{ 
    //variable to indicate sign of input number 
    bool negative = false; 
    register int c; 
  
    number = 0; 
  
    // extract current character from buffer 
    c = getchar(); 
    if (c=='-') 
    { 
        // number is negative 
        negative = true; 
  
        // extract the next character from the buffer 
        c = getchar(); 
    } 
  
    for (; (c>47 && c<58); c=getchar()) 
        number = number *10 + c - 48; 
  
    if (negative) 
        number *= -1; 
} 

void solve(int a){
    if(st)printf("\n");
    st++;
    priority_queue<int,V<int>, greater<int> > right;
    priority_queue<int,V<int> > left;
    left.push(a);
    while(1){
        scanf("%d",&a);
        if(a == -1){
            printf("%d\n",left.top());
            left.pop();
            if(right.size() && right.size() > left.size()){
                left.push(right.top());
                right.pop();
            }
            continue;
        }else if(a == 0){
            // cout << "LEFT: " ;
            // while(left.size()){cout << left.top() << " ";left.pop();}
            // cout << "\nRIGHT: " ;
            // while(right.size()){cout << right.top() << " ";right.pop();}
            // exit(1);
            return;
        }
        if(left.size() == 0)left.push(a);
        else if(a <= left.top())left.push(a);
        else right.push(a);
        if(left.size() < right.size()){
            left.push(right.top());
            right.pop();
        }else if(left.size() > right.size() + 1){
            right.push(left.top());
            left.pop();
        }
    }
}

int main(){
    FAST
    // FILE_READ_IN
    int t = 1;
    scanf("%d",&t);
    while(t--){
        int a;
        scanf("%d",&a);
        solve(a);
    }
    return 0;
}