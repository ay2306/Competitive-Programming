n = input()
inp = raw_input()
arr = [int(e) for e in inp.split(' ')]
arr.sort()
mnx = arr[0]
mxx = arr[n-1]
mny = arr[n]
mxy = arr[(2*n)-1]

print ((mxx-mnx)*(mxy-mny))