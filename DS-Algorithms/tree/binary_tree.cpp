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

class BT{
    struct node{
        int val;
        struct node *left;
        struct node *right;
    };
    struct node *root;
public:
    BT(int val){
        root = newNode(val);
    }
    struct node* newNode(int val){
        struct node* N = new struct node;
        N->left = NULL;
        N->right = NULL;
        N->val = val;
        return N;
    }
    void insertWithPath(string path, int val){
        struct Node* ptr = root;
        for(int i = 0; i+1 < path.length(); ++i){
            if(path[i] == 'L' && ptr->left!=NULL){
                ptr = ptr->left;
            }else if(path[i] == 'L'){
                cout << "PATH INCORRECT";
                return ;
            }if(path[i] == 'R' && ptr->right!=NULL){
                ptr = ptr->right;
            }else if(path[i] == 'R'){
                cout << "PATH INCORRECT";
                return ;
            }
        }
        if(path[path.length()-1] == 'L')ptr->left = newNode(val);
        else ptr->right = newNode(val);
    }
}

int main(){
    
    return 0;
}