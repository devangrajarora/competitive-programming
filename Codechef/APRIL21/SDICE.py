tc = int(input())
for _ in range(tc):
	n = int(input())
	ans = int(n / 4) * 4 * 11
	rem = n % 4
	ok = 1 if n >= 4 else 0 
	if rem == 0:
		ans += 4*4*ok
	elif rem == 1:
		ans += 4*3*ok + (2+3+4+5+6)
	elif rem == 2:
		ans += 4*2*ok + 2*(3+4+5+6)
	else:
		ans += 4*ok + 2*(3+4+5+6) + (4+5+6)

	print(int(ans))