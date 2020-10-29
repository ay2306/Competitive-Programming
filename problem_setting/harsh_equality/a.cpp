#include<bits/stdc++.h>
#define int long long
using namespace std;

template<class X, class Y, class Z>
struct container{
	priority_queue<X,Y,Z> q;
	int sum;
	container():sum(0){}
	void add(int x){
		sum+=x;
		q.emplace(x);
	}
	int top(){return q.top()};
	int pop(){
		int val = q.top();
		sum-=q.top();
		q.pop();
		return val;
	}
	inline size_t size(){return q.size();}
	inline int getsum(){return sum;}
};

int32_t main(){
	container<int,vector<int>,greater<int>> left;
	container<int,vector<int>,less<int>> right;
	int n;
	cin >> n;
	while(n--){
		int a;
		cin >> a;
		left.add(a);
		if(right.size())left.add(right.pop());
		while(left.size() > right.size()+1)right.add(left.pop());
		int mid = left.top();
		cout << left.size()*mid - left.sum + right.sum - right.size()*mid << 
;
	}
	return 0;
}
