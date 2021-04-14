import math
tc = int(input())

def solve():
	n,a,b,k = map(int, input().split())
	lcm = int((a*b)/ math.gcd(a,b))
	solved = int(n/a) + int(n/b) - 2*int(n/lcm)
	print("Win") if k <= solved else print("Lose")

for i in range(tc):
	solve()