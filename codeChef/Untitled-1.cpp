void add_to_current(int x){
	if(arr[x] < 2)return;
	// printf("add %lld to current\nIts primes factors: ",arr[x]);
	map<int,int> f;
	x = arr[x];
	while(x > 1){
		f[pr[x]]++;
		x/=pr[x];
	}
	for(auto &i: f){
		// printf("(p = %d, c = %d) ",i.F,i.S);
		ans*=power(current[i.F]+1,MOD-2);
		ans%=MOD;
		current[i.F]+=i.S;
		ans*=(current[i.F]+1);
		ans%=MOD;
	}
	// printf("\n");
}
void remove_from_current(int x){
	if(arr[x] < 2)return;
	// printf("removing %lld from current\n",arr[x]);
	map<int,int> f;
	x = arr[x];
	while(x > 1){
		f[pr[x]]++;
		x/=pr[x];
	}
	for(auto &i: f){
		ans*=power(current[i.F]+1,MOD-2);
		ans%=MOD;
		current[i.F]+=i.S;
		ans*=(current[i.F]+1);
		ans%=MOD;
	}
}
