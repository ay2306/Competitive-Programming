#include<bits/stdc++.h>
using namespace std;
const int N = 5e4+100;

struct node{
	int parent;
	int eat;
	int eaten;
	node(){}
	node(int parent): parent(parent){}
}*same,*total;

int findParent(node* &p,int x){
	if(x == p[x].parent)return x;
	p[x].parent = findParent(p,p[x].parent);
	return p[x].parent;

}

void join(node* &p, int a, int b){
	a = findParent(p,a);
	b = findParent(p,b);
	p[a].parent = b;
	p[a].eaten = p[b].eaten;
	p[a].eat = p[b].eat;
}

bool connected(node* &p, int a, int b){
	a = findParent(p,a);
	b = findParent(p,b);
	return a == b;
}

int main(){
	int t,a,b,n,k,ans=0;
	cin >> n >> k;
	same = new node[N];
	total = new node[N];
	for(int i = 1; i <= n; ++i){
		same[i] = node(i);
		total[i] = node(i);
	}
	while(k--){
		cin >> t >> a >> b;
		if(t == 1){
			if(a > n || b > n || a == b){
				ans++;
				continue;
			}
			//check if exists in same overall component;
			if(connected(total,a,b)){
				ans += !connected(same,a,b);
			}else{
				join(total,a,b);
				a = findParent(same,a);
				b = findParent(same,b);
				join(same,a,b);
				if(~same[a].eaten && ~same[b].eaten)join(same,same[a].eaten, same[b].eaten);
				if(~same[a].eat && ~same[b].eat)join(same,same[a].eat, same[b].eat);
			}
		}else{
			if(a > n || b > n || a == b){
				ans++;
				continue;
			}
			if(connected(total,a,b)){
				ans += connected(same,a,b);
			}else{
				join(total,a,b);
				a = findParent(same,a);
				b = findParent(same,b);
				if(~same[b].eaten)join(same,same[b].eaten,a);
				else same[b].eaten = findParent(same,a);
				if(~same[a].eat)join(same,same[a].eat,b);
				else same[a].eat = findParent(same,b);
				if(~same[a].eat && ~same[b].eaten)join(same,~same[a].eat, ~same[b].eaten);
			}
		}
		cout << ans;
	}
	return 0;
}