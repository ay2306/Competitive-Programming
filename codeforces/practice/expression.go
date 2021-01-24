package main

import (
	"fmt"
)

func max(a int,b int)int{
	if(a > b){
		return a;
	}else{
		return b;
	}
}

func calculate(a int,b int,c int)int{
	ans := (a+b)*c;
	ans = max(ans,(a+b)+c);
	ans = max(ans,(a*b)+c);
	ans = max(ans,(a*b)*c);
	return ans;
}

func main(){
	var a,b,c int;
	fmt.Scanf("%d\n",&a);
	fmt.Scanf("%d\n",&b);
	fmt.Scanf("%d\n",&c);
	var ans int;
	ans = max(ans,calculate(a,b,c));
	ans = max(ans,calculate(b,c,a));
	fmt.Println(ans);
}