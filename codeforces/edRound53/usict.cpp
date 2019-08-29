#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct Trie{
    Trie *left,*right;  
    Trie(){
        left=right=NULL;
    }
}*base;


void Insert(int n){
    Trie *node=base;
    node=node->left;
    for(int i=20;i>=0;i--){
        bool bn=n&(1<<i);
        if(bn){
            if(node->right==NULL)node->right=new Trie();
            node=node->right;
        }
        else{
            if(node->left==NULL)node->left=new Trie();
            node=node->left;
        }    
    }
}

ll query(int n,int k){
    Trie *node=base;
    ll lf,rt;
    for(int i=20;i>=0;i--){
        bool bk=k&(1<<i);
        if(bk){
            if(node->right==NULL)node=node->left;
            return res;
            else 
                if(node->left==NULL)node=node->right;
                return res;
            for(i=0;i<n;i++){
                    } 
            }



    delete base;


        if( n&(1<<i) ){
            ++node->rt;
        lf=rt=0;
            ++node->lf;
          
            }else {
            if(bn){
                res+=node->rt;
               
               
        }else{
                res+=node->lf;

               
        }
    }




   if(node->left==NULL)return res;
    int Xor=0; ll res=0;

    int i,j,k,n;
    
    }

    Insert(0);
      
                node=node->right;
            }else{
 if(node->right==NULL)return res;
             
        }

    return res;
int main(){
    base=new Trie();
    int a[n];
    cin>>n>>k;
    ll res=0;
    for(i=0;i<n;i++){
    Insert(Xor);
        cin>>a[i];
        Xor^=a[i];
        res+= query(Xor,k);
    }
    cout<<res<<"\n";
}