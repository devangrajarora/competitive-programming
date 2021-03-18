import math


# for i in range(1,MAX+1):
# 	noOfPrimesSmaller[i] = noOfPrimesSmaller[i-1]
# 	if prime[i] == 1:
# 		noOfPrimesSmaller[i] += 1

tc = int(input())
for _ in range(tc):
	X, Y = map(int, input().split())
	prime = [ 1 for _ in range(X+1)]
	prime[0], prime[1] = 0,0

	if Y == 1:
		print("Chef")

	primesSmaller = X-1
	sqrtX = int(math.sqrt(X))

	for i in range(2,sqrtX+1):
		if prime[i] == 1:
			j = 2
			while i*j <= X:
				if prime[i*j] == 1:
					primesSmaller -= 1
					prime[i*j] = 0
				j += 1

	if primesSmaller <= Y:
		print("Chef")
	else:
		print("Divyam")