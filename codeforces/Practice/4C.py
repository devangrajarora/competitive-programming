n = int(input())
db = {}
for i in range(n):
	name = input()
	if name not in db:
		db[name] = 1
		print("OK")
	else:
		print(f'{name}{db[name]}')
		db[name] += 1