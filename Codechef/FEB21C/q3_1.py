tcs = int(input())
for _ in range(tcs):
	n, ans = int(input()), 0
	FW = input().split().sort()
	dic, freq, done =  set(FW), {}, set([])
	counted = [ [0] * 26 for _ in range(26)]

	for fw in FW:
		c = fw[0]
		freq[c] = 1 if c not in  freq else freq[c] + 1

	for fw in FW:
		first, suff = fw[0], fw[1:]

		for i in range(ord('a'), ord(first)):
			small, big = chr(i), first 
			s = small + suff
			if s in dic:
				ans += 2*(freq[small] - counted[ord(small) - ord('a')][ord(big) - ord('a')])

		for i in range(ord(first)+1, ord('z')+1):
			second = chr(i)
			s = second + suff
			if s in dic:
				ans += 2*(freq[second])
				counted[ord(first) - ord('a')][ord(second) - ord('a')] += 1

	for key in freq.keys():
		ans += (freq[key])*(freq[key]-1)

	print((n*(n-1)) - ans)