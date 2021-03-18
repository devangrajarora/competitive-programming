import math

def main():
	n = int(input())
	W = list(map(int,input().split()))
	L = list(map(int,input().split()))
	a = []
	for i in range(n):
		a.append((W[i],i+1,L[i]))
	a.sort()

	if n == 1:
		return 0

	# print(a)
	maxPos, ans = a[0][1], 0
	for i in range(1,n):
		currW, prevW, currPos = a[i][0], a[i-1][0], a[i][1]
		nextPos = maxPos+1 if currW > prevW else maxPos
		if nextPos > currPos:	
			noOfTaps = math.ceil((nextPos - currPos)/a[i][2])
			ans += noOfTaps
			maxPos = currPos + noOfTaps*a[i][2]
		else:
			maxPos = currPos

		# print(nextPos,maxPos)

	return ans



if __name__ == '__main__':
	tcs = int(input())
	for _ in range(tcs):
		print(main())
