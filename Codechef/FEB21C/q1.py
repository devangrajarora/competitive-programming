tcs = int(input())
for _ in range(tcs):
	n = int(input())
	a = list(map(int, input().split()))
	print(2*(max(a) - min(a)))
