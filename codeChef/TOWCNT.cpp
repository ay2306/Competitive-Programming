#include<bits/stdc++.h>
#define big ll
#define ll long long int
using namespace std;

struct tower{
    ll x;
    ll y;
    int t;
    int i;
    tower(){}
    tower(ll x, ll y, int t, int i):x(x),y(y),t(t),i(i){}
    bool operator<(const tower& rhs){
        return x < rhs.x;
    }
};

struct slope{
    ll x,y;
    slope(ll x = 0, ll y = 0):x(x),y(y){}
    bool operator<=(const slope &rhs){
        /*
            dy/dx <= DY/DX
            dy*DX <= DY*dx
        */
        return (y*rhs.x < x*rhs.y);
    }
    void simplify(){
        if(x < 0)x=-x,y=-y;
    }
    void print(){
        printf("dy = %lld, dx = %lld\n",(ll)y,(ll)x);
    }
};

void solve(){
    ll n,h,a,b,c;
    scanf("%lld%lld",&h,&n);
    vector<tower> arr;
    for(int i = 0; i < n; ++i){
        scanf("%lld%lld%lld",&a,&b,&c);
        arr.emplace_back(b,c,(int)a,i);
    }
    sort(arr.begin(),arr.end());
    vector<int> ans(n,0);
    for(int i = 0; i < n; ++i){
        slope up(0,1);
        slope down(0,-1);
        for(int j = i+1; j < n; ++j){
            if(arr[j].x == arr[i].x){
                ans[arr[i].i]++;
                ans[arr[j].i]++;
                continue;
            }
            slope cur(arr[i].x-arr[j].x,arr[i].y-arr[j].y);
            cur.simplify();
            bool add = false;
            if(cur <= up && down <= cur)ans[arr[i].i]++,ans[arr[j].i]++,add=true;
            if(arr[j].t == 0 && down <= cur)down = cur;
            else if (arr[j].t == 1 && cur <= up) up = cur;
        }
    }
    for(auto &i: ans)printf("%d ",i);
    printf("\n");
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--)solve();
    return 0;
}
