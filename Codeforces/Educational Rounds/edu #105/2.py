for tc in range(int(input())):
	n, U, R, D, L = map(int,input().split())
	no = True
	for opt in range(16):
		U1, R1, D1, L1 = U, R, D, L
		if opt & 1:
			U1 -= 1
			R1 -= 1
		if opt & 2:
			R1 -= 1
			D1 -= 1
		if opt & 4:
			D1 -= 1
			L1 -= 1
		if opt & 8:
			L1 -= 1
			U1 -= 1

		if min(U1,R1,D1,L1) >= 0 and max(U1,R1,D1,L1) <= n-2:
			print("YES")
			no = False 
			break 

	if no:
		print("NO")