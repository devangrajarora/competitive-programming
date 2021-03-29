import math

def main():
	n,m,k = list(map(int,input().split()))
	a = list(map(int,input().split()))
	b = list(map(int,input().split()))
	lcm = int(n*m / math.gcd(n,m))

	# print(a)
	# print(b)

	diff, moves, aIdx, bIdx = 0, 0, 0, 0
	for i in range(lcm):
		moves += 1
		if a[aIdx] != b[bIdx]:
			diff += 1
		if diff == k:
			print(moves)
			return
		aIdx = (aIdx + 1) % n
		bIdx = (bIdx + 1) % m

	ans = lcm * int(k/diff)
	cnt = diff * int(k/diff)

	# print(ans)
	
	if cnt < k:
		aIdx, bIdx = 0, 0
		for i in range(lcm):
			ans += 1
			if a[aIdx] != b[bIdx]:
				cnt += 1
				if cnt == k:
					break
			aIdx = (aIdx + 1) % n
			bIdx = (bIdx + 1) % m

	print(ans)

if __name__ == '__main__':
	main()