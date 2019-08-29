#include <bits/stdc++.h>
//For ordered_set
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
#define all(a) a.begin(),a.end()
using namespace std;
// For ordered_set
using namespace __gnu_pbds;
template <typename T>
using ord_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
const ll maxn = 1e5;
const ll inf = 1e9;
const double pi = acos(-1);

int rightDiagonal(pair<int,int> p){
    return p.first + p.second;
}
int leftDiagonal(pair<int,int> p){
    return p.first - p.second;
}
void printInfo(PII a, PII t, PII b, PII l, PII r, PII rt, PII rb, PII lt, PII lb){
    printf("arr = %d %d, ",a.F,a.S);
    printf("top = %d %d, ",t.F,t.S);
    printf("bottom = %d %d, ",b.F,b.S);
    printf("left = %d %d, ",l.F,l.S);
    printf("right = %d %d, ",r.F,r.S);
    printf("right-top = %d %d, ",rt.F,rt.S);
    printf("right-bottom = %d %d, ",rb.F,rb.S);
    printf("left-top = %d %d, ",lt.F,lt.S);
    printf("left-bottom = %d %d\n",lb.F,lb.S);
}

int main(){
   FAST
   int n,m;
   unordered_map<int,pair<int,int>> right_top;
   unordered_map<int,pair<int,int>> right_bottom;
   unordered_map<int,pair<int,int>> left_top;
   unordered_map<int,pair<int,int>> left_bottom;
   unordered_map<int,pair<int,int>> row_left;
   unordered_map<int,pair<int,int>> row_right;
   unordered_map<int,pair<int,int>> col_bottom;
   unordered_map<int,pair<int,int>> col_top;
    V<int> ans(9,0);
   cin >> n >> m;
   V<pair<int,int>> arr(m);
   loop(i,0,m){
       cin >> arr[i].first >> arr[i].second;
       int right = rightDiagonal(arr[i]);
       int left = leftDiagonal(arr[i]);
       if(right_top.find(right) == right_top.end())right_top[right] = arr[i];
       else if(arr[i].second < right_top[right].second)right_top[right] = arr[i];

       if(right_bottom.find(right) == right_bottom.end())right_bottom[right] = arr[i];
       else if(arr[i].second > right_bottom[right].second)right_bottom[right] = arr[i];

       if(left_top.find(left) == left_top.end())left_top[left] = arr[i];
       else if(arr[i].second > left_top[left].second)left_top[left] = arr[i];

       if(left_bottom.find(left) == left_bottom.end())left_bottom[left] = arr[i];
       else if(arr[i].second < left_bottom[left].second)left_bottom[left] = arr[i];

       if(row_left.find(arr[i].first) == row_left.end())row_left[arr[i].first] = arr[i];
       else if(arr[i].second < row_left[arr[i].first].second)row_left[arr[i].first] = arr[i];

       if(row_right.find(arr[i].first) == row_right.end())row_right[arr[i].first] = arr[i];
       else if(arr[i].second > row_right[arr[i].first].second)row_right[arr[i].first] = arr[i];

       if(col_top.find(arr[i].second) == col_top.end())col_top[arr[i].second] = arr[i];
       else if(arr[i].first < col_top[arr[i].second].first)col_top[arr[i].second] = arr[i];

       if(col_bottom.find(arr[i].second) == col_bottom.end())col_bottom[arr[i].second] = arr[i];
       else if(arr[i].first > col_bottom[arr[i].second].first)col_bottom[arr[i].second] = arr[i];
   }

   loop(i,0,m){
       int right = rightDiagonal(arr[i]);
       int left = leftDiagonal(arr[i]);
       int k = 0;
       if(right_top[right] != arr[i])k++;
       if(right_bottom[right] != arr[i])k++;
       if(left_top[left] != arr[i])k++;
       if(left_bottom[left] != arr[i])k++;
       if(row_left[arr[i].first] != arr[i])k++;
       if(row_right[arr[i].first] != arr[i])k++;
       if(col_top[arr[i].second] != arr[i])k++;
       if(col_bottom[arr[i].second] != arr[i])k++;
    //    printInfo(arr[i],col_top[arr[i].second],col_bottom[arr[i].second],row_left[arr[i].first],row_right[arr[i].first],right_top[right],right_bottom[right],left_top[left],left_bottom[left]);
       ans[k]++;
   }
   for(auto i: ans)cout << i << " ";
   return 0;
}