import random
TC = int(input())
for tc in range(1,TC+1):
	bestScore, bestIdx = 0, 1
	for i in range(1,101):
		s = input()
		cnt = s.count('1')
		if cnt > bestScore:
			bestScore, bestIdx = cnt, i

	print(f'Case #{tc}: {bestIdx}')