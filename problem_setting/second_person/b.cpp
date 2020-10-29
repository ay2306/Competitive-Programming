#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	scanf("%d",&n);
	vector<int> a(n);
	for(int &i: a)scanf("%d",&i);
	vector<tuple<int,int,int>> arr;
	for(int i: a){
		if(arr.size() == 0 || get<2>(arr.back()) != i)arr.emplace_back(1,arr.size(),i);
		else get<0>(arr.back())++;
	}
	sort(arr.begin(),arr.end(),[](tuple<int,int,int> a, tuple<int,int,int> b)->bool{
		if(get<0>(a) != get<0>(b))return get<0>(a) > get<0>(b);
		return get<1>(a) < get<1>(b);		
	});
	a.clear();
	for(auto i: arr){
		for(int j = 0; j < get<0>(i); ++j){
			a.emplace_back(get<2>(i));
		}
	}
	for(int i: a)printf("%d ",i);
	return 0;
}
