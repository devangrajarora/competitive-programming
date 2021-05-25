s = input()
a = []
rev = 0

for c in s:
	if c == 'R':
		rev = rev ^ 1
	else:
		if len(a) == 0:
			a.append(c)
		elif rev is 1:
			if c == a[0]:
				a.pop(0)
			else:
				a.insert(0,c)
		elif rev is 0:
			n = len(a)
			if c == a[n-1]:
				a.pop(n-1)
			else:
				a.append(c)

if rev is 1:
	a.reverse()

for c in a:
	print(c,end="")

