def main():
	n, ans = int(input()), 0
	FW = input().split()
	suff = []
	for fw in FW:
		suff.append(fw[1:])
	DFW = set(FW)
	for i in range(n):
		for j in range(i+1,n):
			FW1, FW2 = FW[i], FW[j]
			NFW1 = FW[i][0] + suff[j]
			NFW2 = FW[j][0] + suff[i]
			if NFW1 not in DFW and NFW2 not in DFW:
				ans += 2
			else:
				print(FW1, FW2)
				
	return ans 


if __name__ == '__main__':
	tcs = int(input())
	for _ in range(tcs):
		print(main())
