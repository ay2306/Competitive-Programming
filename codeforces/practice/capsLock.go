package main

import (
	"fmt"
)

func main(){
	var s string;
	fmt.Scanln(&s);
	var cnt int;
	for i := 0; i < len(s); i++{
		if s[i] >= 'A' && s[i] <= 'Z'{
			cnt++;
		}
	}
	extra := 0;
	if (s[0] < 'A' || s[0] > 'Z'){
		extra++;
	}
	res := cnt == len(s) - extra;
	var ans string;
	if (res) { 
		for i:= 0; i < len(s); i++{
			if s[i] >= 'A' && s[i] <= 'Z'{
				ans += string(s[i] - 'A' + 'a');
			}else{
				ans += string(s[i] - 'a' + 'A');
			}
		}
	}else{
		ans = s;
	}
	fmt.Print(ans)
}