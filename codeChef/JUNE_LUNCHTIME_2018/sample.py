def get_input():
    inp = raw_input()
    tmp_array_for_input = []
    for i in inp.split(' '):
        tmp_array_for_input.append(int(i))
    return tmp_array_for_input
    
n = input()
arr = get_input()
sum = 0
el = 0
for i in arr:
    if i >= 0:
        sum = sum+i
        el = el+1
print str(sum) + " " + str(el)