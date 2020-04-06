Consider a $B$ bits binary number with bits $ b_1, b_2 ... b_B$

For case $B <= 10$, we can simply ask for first 10 numbers and get the answer

Let's consider $B > 10$
Ask these queries in the start $b_1,b_{B},b_2,b_{B-1},b_3,b_{B-2},b_4,b_{B-3},b_5,b_{B-4}$

So you had answer for $[b_1,b_2,...,b_5-b_{B-4},...,b_{B}]$

On $11^{th} $ query, this array will be changed
but we can retrieve this new array from $1-5$ and $B-4$ to $B$ in at exactly $2$ queries

There are 3 scenarios for the currently given array:
1. All pallindromic counter-parts are equal.    
   Then if we find out if any element is changed, then it must be complement task
3. All pallindromic counter-parts are different.
   Then if we find out if any of the element is changed, then it can either be complement or inversion, but it doesn't matter because effect of either one will be same on the array we have already discovered
4. It's a mixure of both of them, then we can first find out any pair of same pallindromic counter-part is changed because that means 