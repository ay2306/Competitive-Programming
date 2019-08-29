#include <stdio.h>

int main(){
  int t,n,p,temp,easy,tough;
  scanf("%d",&t);
  while(t--){
    easy = 0;
    tough = 0;
    scanf("%d%d",&N,&P);
    int i = 0;
    for(i = 0; i < N; ++i){
      scanf("%d",&temp);
      if(temp <= (p/10)){
        tough++;
      }else if(temp >= (p/2)){
        easy++;
      }
    }
    if(easy == 1 && tough == 2){
      printf("Yes\n");
    }else{
      printf("No\n");
    }
  }
  return 0;
}