import math

def solve():
	n = int(input())
	a, ans = [], 1
	for i in range(1,n):
		if math.gcd(i,n) == 1:
			a.append(i)
			ans *= i

	a.reverse()
	k = 0
	for i in range(len(a)):
		if ans % n == 1:
			k = i
			break
		else:
			ans /= a[i]

	print(len(a)-k)
	for i in range(len(a)-1,k-1,-1):
		print(a[i],end=" ")

solve()
print()