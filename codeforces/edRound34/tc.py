import sys
import random
sys.stdout = open('inp','w')
def get(a,b):
    return random.randint(a,b)

n = get(1,10)
print(n)
for i in range(n):
    print(get(1,5),end=' ')