def solve():
	n,m,k = map(int, input().split())
	a = [ [ 0 for _ in range(m+1) ] for _ in range(n+1) ]
	for i in range(1,n+1):
		a[i] = [0] + list(map(int, input().split()))
	
	ans = 0

	for i in range(1,n+1):
		for j in range(1,m+1):
			ans += 1 if a[i][j] >= k else 0
			a[i][j] = a[i-1][j] + a[i][j-1] - a[i-1][j-1] + a[i][j]

	for i in range(1,n+1):
		for j in range(1,m+1):
			l = 1
			x, y = i+l, j+l

			while x <= n and y <= m:
				num = (l+1)*(l+1)
				total = a[x][y] - a[x][j-1] - a[i-1][y] + a[i-1][j-1]
				avg = total/num
				if avg >= k:
					ans += 1
				l += 1
				x, y = i+l, j+l


	print(ans) 


tc = int(input())
for _ in range(tc):
	solve()
			
