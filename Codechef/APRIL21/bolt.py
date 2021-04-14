tc = int(input())
for _ in range(tc):
	v,k1,k2,k3 = map(float, input().split())
	ans = round(100 / (v*k1*k2*k3), 2)
	print("YES") if ans < 9.58 else print("NO")