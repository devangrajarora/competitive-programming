s = sorted(input().split('+'))
ans, n = f'{s[0]}', len(s)
for i in range(1,n):
	ans += f'+{s[i]}'
print(ans)