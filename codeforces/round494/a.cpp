// #include <bits/stdc++.h>
// #define MOD 1000000007
// #define test int t; cin>>t; while(t--)
// #define init(arr,val) memset(arr,val,sizeof(arr))
// #define loop(i,a,b) for(int i=a;i<b;i++)
// #define loopr(i,a,b) for(int i=a;i>=b;i--)
// #define loops(i,a,b,step) for(int i=a;i<b;i+=step)
// #define looprs(i,a,b,step) for(int i=a;i>=b;i-=step)
// #define ull unsigned long long int
// #define ll long long int
// #define P pair
// #define PLL pair<long long, long long>
// #define PII pair<int, int>
// #define PUU pair<unsigned long long int, unsigned long long int>
// #define L list
// #define V vector
// #define S set
// #define MS multiset
// #define M map
// #define mp make_pair
// #define pb push_back
// #define MM multimap
// #define IT iterator
// #define RIT reverse_iterator
// #define FAST ios_base::sync_with_stdio(false);cin.tie();cout.tie();

// using namespace std;

// int main(){
//     M<int,int> m;
//     int ans = 0;
//     int n,a;
//     cin >> n;
//     while(n--){
//         cin >> a;
//         if(m.count(a) == 0){
//             m.insert(mp(a,1));
//             if(ans < 1)ans = 1;
//         }else{
//             M<int,int>::IT itr = m.find(a);
//             itr->second++;
//             if(ans < itr->second)ans=itr->second;
//         }
//     }   
//     cout << ans;
    // return 0;

 #include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,i;
    cin>>n;

    int a[1001],val[10001];
    for(i=0;i<n;i++){
        cin>>a[i];
        val[a[i]]++;
    }
    // for(int i = 0; i < 1000; ++i)cout << val[i];
    int x=*max_element(val,val+101);

    cout<<x;


}
