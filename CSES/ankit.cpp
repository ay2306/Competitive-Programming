set<pair<int,char>> s;
for(auto i: m)s.emplace(i.second,i.first);
while(q--){
	cin >> k;
	for(auto i : s){
		if(!(k--))break;
		cout << i.second << " ";
	}
	cout << "\n";
}
