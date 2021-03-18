r,c = map(int,input().split())
for i in range(20):
	print("U",end="")
	for j in range(20*(i+1)):
		print("R",end="")
	for j in range(20*(i+1)):
		print("L",end="")


