tc = int(input())
for TC in range(1,tc+1):
	n, ans = int(input()), 0
	a = list(map(int, input().split()))
	for i in range(n-1):
		minIdx, minElem = i, a[i]
		for j in range(i,n):
			if a[j] < minElem:
				minElem, minIdx = a[j], j
		a[i:minIdx+1] = a[i:minIdx+1][::-1]
		ans += (minIdx - i + 1)
	print(f'Case #{TC}: {ans}')