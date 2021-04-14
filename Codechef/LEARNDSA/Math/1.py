import math
tc = int(input())

def solve():
	a,b= map(int, input().split())
	print(math.gcd(a,b))
	
for i in range(tc):
	solve()