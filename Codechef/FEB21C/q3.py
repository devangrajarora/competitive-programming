def main():
	n, ans = int(input()), 0
	FW = input().split()
	dic, freq = {}, {}
	s = set([])
	for fw in FW:
		c, suff = fw[0], fw[1:]
		if c not in freq:
			freq[c] = 1
		else:
			freq[c] += 1
		if suff not in dic:
			dic[suff] = [c]
		else:
			dic[suff].append(c)


	for suff in dic.keys():
		# print(suff,end=" ")
		nn = len(dic[suff])
		dic[suff].sort()
		ans += (nn)*(nn-1)
		smallans = 0
		for i in range(nn):
			for j in range(nn):
				if i == j:
					continue
				pair = (dic[suff][i], dic[suff][j])
				if pair not in s:
					smallans += (freq[dic[suff][j]]-1)
					s.add(pair)

		ans += 2 * smallans
		# print(ans)

	for c in freq.keys():
		ans += (freq[c])*(freq[c]-1)
	# print(ans)

	ans = (n*(n-1)) - ans
	return 0 if ans < 0 else ans


if __name__ == '__main__':
	tcs = int(input())
	for _ in range(tcs):
		print(main())
