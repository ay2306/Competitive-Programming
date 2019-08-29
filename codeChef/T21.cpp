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
#define FILE_READ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
using namespace std;

int main(){
    int v[1000] = {0};
    for(int i = 2; i < 1000; ++i)if(v[i] == 0)for(int j = 2; i*j < 1000; ++j)v[i*j]=1;
    int t;
    scanf("%d",&t);
    while(t--){
        char a[100100];
        scanf("%s",a);
        int n = strlen(a);
        int ans = 0;
        for(int i = 0; i < n; ++i){
            ans = (ans + int(a[i]-'0')%3)%3;
        }
        scanf("%s",a);
        n = strlen(a);
        int ans2 = 0;
        for(int i = 0; i < n; ++i){
            ans2 = (ans2 + int(a[i]-'0')%3)%3;
        }
        ans = (ans%3 * ans2%3)%3;
        printf("%d\n",ans);
    }
    return 0;
}