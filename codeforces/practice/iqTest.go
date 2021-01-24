package main

import (
	"fmt"
)

func main(){
	var x int;
	var arr[2][] int;
	var n int;
	fmt.Scanf("%d\n",&n);
	for i := 0; i < n; i++{
		fmt.Scanf("%d",&x);
		arr[x%2] = append(arr[x%2],i);
	}
	if(len(arr[0]) == 1){
		fmt.Printf("%d",arr[0][0]+1);
	}else{
		fmt.Printf("%d",arr[1][0]+1);
	}
}