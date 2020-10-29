def factorial(n):
    if n < 0:
        return 0
    if n <= 1:
        return 1
    return n*factorial(n-1)
def ncr(n,r):
    if n < 0 or r < 0 or n < r:
        return 0
    return factorial(n)//factorial(r)//factorial(n-r)


n = int(input())
left_choice = ncr(n,n//2)//2
left = factorial(n//2)
right = left
left = left//(n//2)
right = right//(n//2)
print(left_choice*left*right)