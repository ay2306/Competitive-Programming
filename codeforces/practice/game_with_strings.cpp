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
#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);
using namespace std;

const ll maxn = 1e5;

struct node{
    char a;
    struct node* next;
    struct node* prev;
};


class linklist{
    struct node* front;
    struct node* rear;
    struct node* newNode(char a);
    void deleteNode(struct node* ptr);
    void insert(char a);
    int ans;
    public:
        linklist(string a){
            front = NULL;
            rear = NULL;
            ans = 0;
            for(auto i: a){
                insert(i);
            }
            // display();
            calculate();
        }
        void calculate(){
            // cout << "CAL START\n";
            struct node* ptr = front;
            ptr = ptr->next;
            while(ptr != NULL){
                if(ptr->prev == NULL){ptr=ptr->next;continue;}
                if(ptr->prev->a == ptr->a){
                    ans++;
                    deleteNode(ptr->prev);
                    ptr = ptr->next;
                    if(ptr != NULL)deleteNode(ptr->prev);
                }else{
                    ptr = ptr->next;
                }
                // cout << ptr->a << " ";
                // display();
            }
        }
        void display(){
            struct node *ptr = front;
            while(ptr!=NULL){
                cout << ptr->a;
                ptr=ptr->next;
            }
            cout << endl;
            ptr = rear;
            while(ptr!=NULL){
                cout << ptr->a;
                ptr=ptr->prev;
            }
            cout << endl;
        }
        int getAns(){
            return ans;
        }
};

struct node* linklist::newNode(char a){
    struct node* ptr = new struct node;
    ptr->a = a;
    ptr->next = NULL;
    ptr->prev = NULL;
    return ptr;
}

void linklist::deleteNode(struct node* ptr){
    struct node* prev = ptr->prev;
    struct node* next = ptr->next;
    if(prev != NULL){
        prev->next = next;
    }
    if(next != NULL){
        next->prev = prev;
    }
    delete ptr;
}
void linklist::insert(char a){
    if(front == rear && front == NULL){
        front = newNode(a);
        rear = front;
        return;
    }
    rear->next = newNode(a);
    rear->next->prev = rear;
    rear = rear->next;
}

int main(){
    string a;
    cin >> a;
    linklist b(a);
    int c = b.getAns();
    // cout << c << "\n";
    if(c%2 == 0)cout << "No\n";
    else cout << "Yes\n";
    return 0;
}