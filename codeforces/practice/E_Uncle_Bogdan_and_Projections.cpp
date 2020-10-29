// Um_nik's code
// Learning  
#include<bits/stdc++.h>
#define int long long
using namespace std;

struct fraction{
    int num,denom;
    fraction():num(0),denom(1){}
    fraction(int a, int b){
        num = a;
        denom = b;
        if(denom < 0){
            num *= -1;
            denom *= -1;
        }
    }
    bool operator< (const fraction& rhs)const{
        return num*rhs.denom < rhs.num*denom;
    }
    bool operator> (const fraction& rhs)const{
        return num*rhs.denom > rhs.num*denom;
    }
    bool operator==(const fraction& rhs)const{
        return num*rhs.denom == rhs.num*denom;
    }
};

struct segment{
    int l,r,y;
    segment(){}
    void scan(){
        scanf("%lld%lld%lld",&l,&r,&y);
    }
    bool operator<(const segment &rhs)const{
        return y < rhs.y;
    }
};

fraction getSlope(pair<int,int> p1, pair<int,int> p2){
    return fraction(p2.first-p1.first,p1.second-p2.second);
}

int n;
vector<segment> arr;
vector<pair<fraction,fraction>> slopes;

int32_t main(){
    scanf("%lld",&n);
    arr.resize(n);
    for(int i = 0; i < n; ++i)arr[i].scan();
    sort(arr.begin(),arr.end());
    for(int i = 0; i < n; ++i){
        for(int j = i + 1; j < n; ++j){
            if(arr[i].y == arr[j].y)continue;
            fraction slope1 = getSlope(pair<int,int> (arr[i].l, arr[i].y), pair<int,int> (arr[j].r,arr[j].y));
            fraction slope2 = getSlope(pair<int,int> (arr[i].r, arr[i].y), pair<int,int> (arr[j].l,arr[j].y));
            if(slope1 > slope2)swap(slope1,slope2);
            slopes.emplace_back(slope1,slope2);
        }
    }
    if(slopes.size() == 0){
        int L = LLONG_MAX, R = LLONG_MIN;
        for(auto &i: arr)L = min(i.l,L), R = max(i.r, R);
        return printf("%.10lf",(double)(R-L)),0;
    }
    sort(slopes.begin(),slopes.end());
    int index = 1;
    for(int i = 1; i < slopes.size(); ++i){
        if(slopes[i].first < slopes[index - 1].second){
            slopes[index-1].second = max(slopes[i].second,slopes[index-1].second);
        }else{
            slopes[index++] = slopes[i];
        }
    }
    slopes.resize(index);
    vector<pair<fraction,int>> c(n),d(n);
    int cz = 0, dz = 0;
    for(int i = n-1; i >= 0; --i){
        while(cz > 0){
            int id = c[cz-1].second;
            auto slope = c[cz-1].first;
            if(arr[id].l * slope.denom + arr[id].y * slope.num > arr[i].l * slope.denom + arr[i].y * slope.num){
                cz--;
                continue;
            }
            if(arr[id].y == arr[i].y)break;
            slope = getSlope(pair<int,int> (arr[i].l,arr[i].y), pair<int,int> (arr[id].l,arr[id].y));
            c[cz++] = make_pair(slope, i);
            break;
        }
        if(cz == 0)c[cz++] = make_pair(slopes[0].first,i);
    }
    for(int i = 0; i < n; ++i){
        while(dz > 0){
            int id = d[dz-1].second;
            auto slope = d[dz-1].first;
            if(arr[id].r * slope.denom + arr[id].y * slope.num < arr[i].r * slope.denom + arr[i].y * slope.num){
                dz--;
                continue;
            }
            if(arr[id].y == arr[i].y)break;
            slope = getSlope(pair<int,int> (arr[i].r,arr[i].y), pair<int,int> (arr[id].r,arr[id].y));
            d[dz++] = make_pair(slope, i);
            break;
        }
        if(dz == 0)d[dz++] = make_pair(slopes[0].first,i);
    }
    int cp = 0, dp = 0;
    double ans = 1e30;
    for(int i = 0; i < slopes.size(); ++i){
        fraction slope;
        double w;
        int id1,id2;
        slope = slopes[i].first;
        w = (double)slope.num/slope.denom;
        while(cp + 1 < cz && c[cp + 1].first < slope)cp++;
        while(dp + 1 < dz && d[dp + 1].first < slope)dp++;
        id1 = c[cp].second, id2 = d[dp].second;
        ans = min( ans , arr[id2].r + arr[id2].y * w - arr[id1].l - arr[id1].y * w);

        slope = slopes[i].second;
        w = (double)slope.num/slope.denom;
        while(cp + 1 < cz && c[cp + 1].first < slope)cp++;
        while(dp + 1 < dz && d[dp + 1].first < slope)dp++;
        id1 = c[cp].second, id2 = d[dp].second;
        ans = min( ans , arr[id2].r + arr[id2].y * w - arr[id1].l - arr[id1].y * w);
    }
    printf("%.15lf\n",ans);
    return 0;
}