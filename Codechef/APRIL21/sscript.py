def solve():
	n,k = map(int, input().split())
	s, cnt = input(), 0
	for c in s:
		if c == '*':
			cnt += 1
		else:
			cnt = 0
		if cnt >= k:
			print("YES")
			return
	print("NO")


tc = int(input())
for _ in range(tc):
	solve()
			
