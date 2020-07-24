#pragma GCC Optimize("O3")
#include<bits/stdc++.h>
using namespace std;
const int N = 2e5;
int z[N],zr[N];
int max_till_here[N];
bool check(vector<char> &a, vector<char> &b, string &c){
	a.insert(a.begin(),'#');
	b.insert(b.begin(),'#');
	for(int i = 0; i < c.size(); ++i){
		a.insert(a.begin(),c[c.size()-1-i]);
		b.insert(b.begin(),c[i]);
	}
	memset(zr,0,sizeof(zr));
	memset(z,0,sizeof(z));
	memset(max_till_here,0,sizeof(max_till_here));
	int zsize = a.size();
	for(int i = 1, l = 0, r = 0, lr = 0, rr = 0; i < zsize; ++i){
		if(i <= r)z[i] = min(z[i-l],r-i+1);
		if(i <= rr)zr[i] = min(zr[i-lr],rr-i+1);
		while(i+z[i] < zsize && a[z[i]] == a[z[i]+i])z[i]++;
		while(i+zr[i] < zsize && b[zr[i]] == b[zr[i]+i])zr[i]++;
		if(i+z[i]-1 > r)l=i,r=z[i]+i-1;
		if(i+zr[i]-1 > rr)lr=i,rr=zr[i]+i-1;
	}
	int st = 0;
	for(;a[st++]!='#';);
	int mx = 0;
	int csize = c.size();
	reverse(zr+st,zr+zsize);
	a.erase(a.begin(),a.begin()+st);
	b.erase(b.begin(),b.begin()+st);
	for(int i = st; i < zsize; ++i){
		max_till_here[i] = mx;
		if(zr[i] == csize || z[i] == csize)return true;
		int prev_ind = i - zr[i] + 1;
		int rem = csize - zr[i];
		prev_ind = prev_ind-rem+1;
		if(prev_ind >= st && zr[i] + max_till_here[prev_ind] >= csize)return true;
		mx = max(mx,z[i]); 

	}
	if(mx == a.size())return true;
	return false;
}

int main(){
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	string a,s;
	cin >> a;
	vector<char>arr(a.begin(),a.end()),rev(a.begin(),a.end());
	reverse(rev.begin(),rev.end());
	int m,ans=0;
	cin >> m;
	while(m--){
		cin >> s;
		if(s.size() > a.size() || s.size() < 2)continue;
		ans+=check(arr,rev,s);
	}
	return cout << ans << "\n", 0;
}