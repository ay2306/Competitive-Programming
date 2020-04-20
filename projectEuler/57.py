num = 3
denom = 2
cnt = 0
for i in range(1000):
    # print(num,denom)
    if (len(str(num)) > len(str(denom))):
        cnt+=1
    a = denom+num
    b = a+denom
    num = b
    denom = a
print(cnt)