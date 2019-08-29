#include<iostream>
#include<vector>
#include<stdio.h>
using namespace std;

  vector<int> sieve(int limit){
      vector<pair<int,bool> > vec;
      pair<int, bool> p;
      for(int i = 2; i <= limit; ++i){
          p.first = i;
          p.second = true;
          vec.push_back(p);
      }
      int i = 2;
      while(true){
          int itr = false;
          for(int j = (2*i)-2; j <= limit; j+=i){
              if(vec[j].second){
                  vec[j].second = false;
                  itr = true;
              }
          }
          if(!itr)break;
          ++i;
          while(!vec[i-2].second)++i;
      }
      vector<int> res;
      for(int i = 0; i < vec.size(); ++i){
          if(vec[i].second)res.push_back(vec[i].first);
      }
      return res;
  }


int main(){
	vector<int> vec = sieve(1111112);
	FILE *fp;
	fp = fopen("hehe","w");
	fprintf(fp,"int vec[] = {%d",vec[0]);
	for(int i = 1; i < vec.size(); ++i){
		fprintf(fp,",%d",vec[i]);
	}
	fprintf(fp,"};");
	fclose(fp);
	// cout << vec.size(); 
    printf("%lld\n",vec.size());
return 0;
}
