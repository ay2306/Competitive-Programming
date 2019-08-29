#include <bits/stdc++.h>
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

int Case(char a){
    if(a>='a' && a<='z')return 1;
    return 0;
}

int main(){
    string a;
    cin >> a;
    int u=0,l=0;
    for(int i = 0; i < a.length(); ++i){
        if(Case(a[i]))l++;
        else u++;
    }
    if(l >= u){
        for(int i = 0; i < a.length(); ++i){
            if(Case(a[i]))cout << a[i];
            else cout << char(a[i]-'A'+'a');
        }
    }else{
        for(int i = 0; i < a.length(); ++i){
            if(Case(a[i]))cout << char(a[i]-'a'+'A');
            else cout << a[i];
        }
    }
    return 0;
}