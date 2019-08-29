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

// int main(){
//     string a,b;
//     cin >> a >> b;
//     V<int> v;
//     v.pb(0);
//     int pos = 0;
//     for(int i = 0;i < a.length(); ++i){
//         if(b[i] == '+'){
//             for(int j = 0; j < v.size(); ++j)v[j]++;
//         }
//         if(b[i] == '-'){
//             for(int j = 0; j < v.size(); ++j)v[j]--;
//         }
//         if(b[i] == '?'){
//             V<int> tmp;
//             for(int j = 0; j < v.size(); ++j)tmp.pb(v[j]-1);
//             for(int j = 0; j < v.size(); ++j)tmp.pb(v[j]+1);
//             v = tmp;
//         }
//         if(a[i] == '+')pos++;
//         else pos--;
//     }
//     // cout << "POS = " << pos << endl;
//     // for(int i = 0; i < v.size(); ++i)cout << v[i] << " ";
//     // cout << endl;
//     M<int,int> m;
//     m.insert(mp(pos,0));
//     for(int i = 0; i < v.size(); ++i){
//         if(m.count(v[i]) == 0){
//             m.insert(mp(v[i],1));
//         }else{
//             m.find(v[i])->second++;
//         }
//     }
//     printf("%.12f",double(m.find(pos)->second)/double(v.size()));
//     return 0;
// }
int pos = 0;
static int ans = 0;
static int c = 0;
void calPos(string a, int i, int des, int pos){
    if(i == a.length()){
        if(pos == des){
            ans++;
        }
        c++;
        return;
    }
    if(a[i] == '?'){
        calPos(a,i+1,des,pos+1);
        calPos(a,i+1,des,pos-1);
        return ;
    }
    if(a[i] == '-'){
        calPos(a,i+1,des,pos-1);
        // calPos(a,i+1,des,pos-1);
        return ;
    }
    if(a[i] == '+'){
        calPos(a,i+1,des,pos+1);
        // calPos(a,i+1,des,pos-1);
        return ;
    }

}
int main(){
    int des = 0;
    string a;
    cin >> a;
    for(int i = 0; i < a.length(); ++i){
        if(a[i] == '-')des--;
        else des++;
    }
    cin >> a;
    calPos(a,0,des,0);
    printf("%.12f",(double(ans)/double(c)));
    return 0;
}