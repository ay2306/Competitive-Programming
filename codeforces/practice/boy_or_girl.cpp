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

int main(){
    string a;
    cin >> a;
    set<char> s;
    int c = 0;
    for(int i =0 ; i < a.length();++i){
        if(!binary_search(s.begin(),s.end(),a[i])){
            s.insert(a[i]);
            c++;
        }
    }
    if(c%2){
        cout << "IGNORE HIM!";
    }else{
        cout << "CHAT WITH HER!";
    }
    return 0;
}