n = int(input())
l, h, commas, p = 0, 999, 0, 3
ok, ans = True, 0

while h <= n or ok:
	ans += (min(h,n) - l)*commas;
	commas += 1
	l = (10**p) - 1
	p += 3
	if h > n:
		ok = False
	h = (10**p) - 1

print(ans)