#include<bits/stdc++.h>
#define PII pair<ll,pair<ll,ll> >
#define ll long long int
#define pb push_back
#define mp make_pair
using namespace std;
ll n,m,s;
bool comp1(PII a,PII b){
    if(a.first < b.first)return true;
    return false;
}
bool comp(PII a,PII b){
    if(a.first > b.first)return true;
    return false;
}
vector<int> parent;
vector<PII> arr;
map<PII,ll> inMST;
int findParent(int x){
    while(x!=parent[x]){
        parent[x] = parent[parent[x]];
        x = parent[x];
    }
    return x;
}
void UNION(int a, int b){
    int p_a = findParent(a);
    int p_b = findParent(b);
    parent[p_a] = p_b;
}
    pair<ll,ll> kruskal(){
    sort(arr.begin(),arr.end(),comp);
    for(int i = 0 ; i < arr.size(); ++i){
        int a = arr[i].second.first;
        int b = arr[i].second.second;
        if(findParent(a) != findParent(b)){
            UNION(a,b);
            inMST[arr[i]]++;
        }
    }   
    pair<ll,ll> ans = mp(0*1LL,0*1LL);
    sort(arr.begin(),arr.end(),comp1);
    for(int i = 0 ; i < arr.size(); ++i){
        if(inMST.find(arr[i]) == inMST.end()){
            if(s-arr[i].first >= 0 ){
                ans.first++;
                ans.second+=arr[i].first;
                s-=arr[i].first;
            }else{
                break;
            }
        }
    }
    return ans;
}


int main() {
    freopen("input.txt","r",stdin);
    cin >> n >> m >> s;
    parent = vector<int> (n,0);
    for(int i = 1; i < n; ++i){
        parent[i] = i;
    }
    for(int i = 0 ; i < m ;++i){
        ll a,b,c;
        cin >> a >> b >> c;
        a--;
        b--;
        arr.push_back(mp(c,mp(a,b)));
    }
    pair<ll,ll> ans = kruskal();
    cout << ans.first;
	return 0;
}