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

class Simulate{
    stack<char> p1,p2;
    queue<char> pile;
    int chance;
public:
    Simulate(stack<char>& P1, stack<char>& P2){
        this->p2 = P1;
        this->p2 = P2;
        chance = 0;
        PII a = game();
        if(a.first == 0){
            cout << "2 " << a.second;
        }else{
            cout << "1 " << a.first;
        }
    }
    pair<int,int> game(){
        while(p1.size() && p2.size()){
            if(!chance){
                if(p1.size() && (p1.top() >= '1' && p1.top() <= '9') || p1.top() == 'T'){
                    pile.push(p1.top());
                    p1.pop();
                }else{
                    int ch = chance;
                    pile.push(p1.top());
                    p1.top();
                    callFace(pile.front(),(ch^1));
                    if(p2.size() == 0)break;
                    while(pile.size()){
                        p1.push(pile.front());
                        pile.pop();
                    }
                }
            }
            if(chance){
                if(p2.size() && (p2.top() >= '1' && p2.top() <= '9') || p2.top() == 'T'){
                    pile.push(p2.top());
                    p2.pop();
                }else{
                    int ch = chance;
                    pile.push(p2.top());
                    p2.top();
                    callFace(pile.front(),(ch^1));
                    if(p1.size() == 0)break;
                    while(pile.size()){
                        p2.push(pile.front());
                        pile.pop();
                    }
                }
            }
        }
        return mp(p1.size(),p2.size());
    }
    void callFace(char f, int chance){
        int a;
        switch(f){
            case 'J': a = 1;
                      break;
            case 'Q': a = 2;
                      break;
            case 'K': a = 3;
                      break;
            case 'A': a = 4;
                      break;
        }
        if(!chance){
            int i;
            for(i = 0; i < a; ++i){
                if(p1.size() && (p1.top() >= '1' && p1.top() <= '9') || p1.top() == 'T'){
                    pile.push(p1.top());
                    p1.pop();
                }else{
                    break;
                }
                if(p1.size() == 0)return;
            }
            if(i != a){
                pile.push(p1.top());
                p1.pop();
                if(p1.size() == 0)return;
                callFace(pile.front(),(chance^1));
            }
        if(chance){
            int i;
            for(i = 0; i < a; ++i){
                if(p2.size() && (p2.top() >= '1' && p2.top() <= '9') || p2.top() == 'T'){
                    pile.push(p2.top());
                    p2.pop();
                }else{
                    break;
                }
                if(p2.size() == 0)return;
            }
            if(i != a){
                pile.push(p2.top());
                p2.pop();
                if(p2.size() == 0)return;
                callFace(pile.front(),(chance^1));
            }
        }
         
    }
};

int main(){
    while(1){
        string a;
        getline(cin,a);
        if(a[0] == '#')break;
        string b,C,d;
        getline(cin,b);
        getline(cin,C);
        getline(cin,d);
        stack<char> A[2];
        int c = 0;
        for(int i = 0 ; i < a.length(); ++i){
            if(i + 1 == a.length())A[(c++)%2].push(a[i]);
            else if(a[i+1] == ' ')A[(c++)%2].push(a[i]);
        }
        for(int i = 0 ; i < b.length(); ++i){
            if(i + 1 == b.length())A[(c++)%2].push(b[i]);
            else if(b[i+1] == ' ')A[(c++)%2].push(b[i]);
        }
        for(int i = 0 ; i < C.length(); ++i){
            if(i + 1 == C.length())A[(c++)%2].push(C[i]);
            else if(C[i+1] == ' ')A[(c++)%2].push(C[i]);
        }
        for(int i = 0 ; i < d.length(); ++i){
            if(i + 1 == d.length())A[(c++)%2].push(d[i]);
            else if(d[i+1] == ' ')A[(c++)%2].push(d[i]);
        }
        Simulate t(A[0],A[1]);
    }
    return 0;
}