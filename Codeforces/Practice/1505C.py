s = input()
a = []
for c in s:
	a.append(ord(c)-ord('A'))
n = len(a)	
# print(a)
if n <= 2:
	print("YES")
else:
	for i in range(2,n):
		if a[i] != (a[i-1] + a[i-2]) % 26:
			print("NO")
			exit()
	print("YES")