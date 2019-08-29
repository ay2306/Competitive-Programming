t = int(input())
for i in range(t):
	arr = [int(e) for e in input().split()]
	ans = 1
	for k in arr:
		ans = ans*k
	print(ans)