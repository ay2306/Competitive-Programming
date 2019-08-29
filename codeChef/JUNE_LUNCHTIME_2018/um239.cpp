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

int main(){
    int t;
    cin >> t;
    while(t--){
        int l,r,ans=0;
        cin >> l >> r;
        if(l == r){
            if(l%10 == 3 || l%10 == 2 || l%10 ==9)ans++;
        }
        else if(l%100 != l %100){
            if(l%10 <= 2){ans+=3;}//cout << "1\n";}
            else if(l%10 == 3){ans+=2;}//cout << "2\n";}
            else if(l%10 <= 9){ans++;}//cout << "3\n";}
            l = l-(l%10)+10;
            if(r%10 >= 9){ans+=3;}//cout << "4\n";}
            else if(r%10 >= 3){ans+=2;}//cout << "5\n";}
            else if(l%10 >= 2){ans++;}//cout << "6\n";}
            r = r-(r%10);
            // cout << l << " " << r << endl;
            if(l <= r){
                ans+=((r-l)/10)*3;
            }
        }else{
            while(l<=r){
                if(l%10 == 3 || l%10 == 2 || l%10 ==9)ans++;
                ++l;
            }
        }
        cout << ans << endl;
    }   
    return 0;
}