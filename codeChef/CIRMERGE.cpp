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

struct node{
    int val;
    int nxt_sum;
    node *next;
    node *prev;
};
class circular_link_list{
    struct node* start;
    struct node* rear;
    size_t sz;
public:
    circular_link_list();
    struct node* newNode(int val);
    void insert_node(int val);
    void delete_node(struct node* ptr);
    size_t size();
    void setSum();
    struct node* mx_sum();
};
circular_link_list::circular_link_list(){
    sz = 0;
    start = NULL;
    rear = NULL;
}
struct node* circular_link_list::newNode(int val){
    struct node* ptr = new struct node;
    ptr->val = val;
    ptr->next = NULL;
    ptr->prev = NULL;
    return ptr;
}
void circular_link_list::insert_node(int val){
    sz++;
    if(sz == 1){
        start = newNode(val);
        rear = start;
        return;
    }
    rear->next = newNode(val);
    rear->next->next = start;
    rear->next->prev = rear;
    start->prev = rear->next;
    rear = rear->next;
    return;
}
void circular_link_list::delete_node(struct node* ptr){
    if(sz == 0){
        printf("UNDERR: Underflow Error, You are deleting nodes than what exists in the list\n");
        exit(0);
    }
    if(sz > 0)sz--;
    if(sz == 0){
        delete rear;
        start = NULL;
        rear = NULL;
        return;
    }else{
        ptr->prev->next = ptr->next;
        ptr->next->prev = ptr->prev;
        if(ptr == start){
            start = ptr->next;
        }
        if(rear == ptr){
            rear = rear->prev;
        }
        delete ptr;
    }
}
size_t circular_link_list::size(){
    return sz;
}

void circular_link_list::setSum(){
    struct node* ptr = start;
    do{
        ptr->nxt_sum = ptr->val + ptr->next->val;
        ptr = ptr->next;
    }while(ptr != start);
}

struct node* circular_link_list::mx_sum(){
    struct node* ans = start;
    struct node* ptr = start->next;
    while(ptr != start){
        if(ans->nxt_sum > ptr->nxt_sum)ans = ptr;
        ptr = ptr->next;
    }
    return ans;
}

void solve(){
    circular_link_list s;
    int n;
    cin >> n;
    loop(i,0,n){
        int a;
        cin >> a;
        s.insert_node(a);
    }
    ll ans = 0;
    while(s.size() > 1){
        s.setSum();
        struct node* ptr = s.mx_sum();
        ptr->val = ptr->nxt_sum;
        ans+=ptr->nxt_sum;
        s.delete_node(ptr->next);
    }
    cout << ans << "\n";
}

int main(){
   int t = 0;
   cin >> t;
   while(t--){
       solve();
   }
   return 0;
}