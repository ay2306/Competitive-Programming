#include <iostream>

using namespace std;

void build(int tree[],int A[], int node, int start, int last){
    if(start == last)tree[node] = A[start];
        else{
        build(tree,A,2*node,start,mid);
        int mid = (start + last)/2;
        build(tree,A,2*node+1,mid+1,last);
        tree[node] = tree[2*node] + tree[2*node + 1];
    }
}

void update(int tree[], int A[], int node, int start, int last, int idx, int val){
    if(start == last){
        A[idx]+=val;
        tree[node]+=val;
    }
    else{
        int mid = (start + last)/2;
        if(start <= idx && idx <= mid)update(tree,A,2*node,start,mid,idx,val);
        else{
            update(tree,A,2*node+1,mid+1,last,idx,val);
        }
        tree[node] = tree[2*node] + tree[2*node + 1];
    }
}

int query(int tree[], int node, int start, int last, int l, int r){
    if(r<start || last<l)return 0;
    if(l<=start && last<=r)return tree[node];
    int mid = (start + last)/2;
    int p1 = query(tree,2*node,start,mid,l,r);
    int p2 = query(tree,2*node+1,mid+1,last,l,r);
    return (p1+p2);
}

int main(){
    int n;
    cin >> n;
    int *a = new int[n+1];
    for(int i = 1; i <= n; ++i)cin >> a[i];
    int f,g,k = n;
    int sum = 0;
    while(k){
        sum+=k;
        k/=2;
    }
    int *tree = new int[sum+1];
    for(int i = 1; i <= sum ; ++i)tree[i]=0;
    build(tree,a,1,1,n);
    int q;
    int treeh = sum;
    cin >> q;
    while(q--){
        cin >> k;
        if(k==1){
            cin >> f >> g;
            for(int i = 1; i <= n; ++i)cout << a[i] << " ";
            update(tree,a,1,1,n,f,g);
            cout << endl;
            for(int i = 1; i <= treeh; ++i)cout << tree[i] << " ";
            cout << endl;
        }
        if(k==2){
            cin >> f >> g;
            cout << query(tree, 1, 1, n, f, g) << "\n";
        }
    }
return 0;
}
/*

#include<iostream>

using namespace std;

int main(){
    int n;
    bool pos = true;
    cin >> n;
    int spec = 3;
    int play[2] = {1,2};
    while(n--){
        int a;
        cin >> a;
        if(a==spec){
            pos = false;
            break;
        }
        if(play[0]==a){
            int k = play[1];
            play[1] = spec;
            spec = k;
        }
        else if(play[1]==a){
            int k = play[0];
            play[0] = spec;
            spec = k;
        }
    }
    if(pos)cout<<"YES";
    else{
        cout <<"NO";
    }
}

*/
