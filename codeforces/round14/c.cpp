#include<bits/stdc++.h>
#define ll long long int
#define mp make_pair
#define V vector
#define P pair
#define mp make_pair
#define pb emplace_back
#define all(a) a.begin(), a.end()
#define C continue;
#define loop(a,b,c) for(int a = b; a < c; ++a)
#define PII pair<int,int>
#define PLL pair<long long, long long>
#define ld long double
#define xx first
#define yy second
#define fst ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

const int inf = 1e9;
const int mod = 1e9+7;
PII read(PII &a){
    cin >> a.xx >> a.yy;
    return a;
}

bool xp(PII a, PII b){
    return a.yy == b.yy;
}
bool yp(PII a, PII b){
    return a.xx == b.xx;
}

int main(){
    map<PII,int> f;
    map<P<PII,PII>,int> f1;
    int y = 0, x = 0;
    PII a,b;
    loop(i,0,4){
        a = read(a);
        b = read(b);
        if(a > b)swap(a,b);
        if(f1[mp(a,b)] || (a == b) || (!xp(a,b) && !yp(a,b)))return cout << "NO\n",0;
        if(xp(a,b))x++;
        if(yp(a,b))y++;
        f[a]++;
        f[b]++;
        f1[mp(a,b)]++;
    }
    if(f.size() == 4 && y == 2 && x == 2)return cout << "YES\n",0;
    return cout << "NO\n",0;

}   