#include<bits/stdc++.h>
using namespace std;

struct point{
    long long int x,y,id;
};

struct cmp_x{
    bool operator()(const point &a, const point &b)const{
        return a.x < b.x || (a.x == b.x && a.y < b.y);
    }
};

struct cmp_y{
    bool operator()(const point &a, const point &b)const{
        return a.y < b.y;
    }
};

int n;
vector<point> arr;

long long int mindist;
pair<long long int,long long int> bestPair;

void update_ans(const point &a, const point &b){
    long long int dist = (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
    if(dist < mindist){
        mindist = dist;
        bestPair = make_pair(a.id,b.id);
    }
}

vector<point> t;

void rec(int l, int r){
    if(r-l <= 3){
        for(int i = l; i < r; ++i){
            for(int j = i+1; j < r; ++j){
                update_ans(arr[i],arr[j]);
            }
        }
        sort(arr.begin()+l,arr.begin()+r,cmp_y());
        return;
    }
    int m = (l+r) >> 1;
    long long int midx = arr[m].x;
    rec(l,m);
    rec(m,r);
    merge(arr.begin()+l,arr.begin()+m,arr.begin()+m,arr.begin()+r,t.begin(),cmp_y());
    copy(t.begin(),t.begin()+r-l,arr.begin()+l);
}

int main(){

}