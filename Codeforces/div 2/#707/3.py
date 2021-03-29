def main():
	n = int(input())
	a = list(map(int,input().split()))
	dic = {}

	for i in range(n-1):
		for j in range(i+1,n):

			SUM = a[i] + a[j]
			if SUM not in dic:
				dic[SUM] = set()

			dic[SUM].add(i)
			dic[SUM].add(j)

			sz = len(dic[SUM])

			if sz == 4:
				i,j,k,l = [idx + 1 for idx in list(dic[SUM])]

				if a[i-1] + a[j-1] == a[k-1] + a[l-1]:
					print("YES")
					print(i,j,k,l)
					return
				elif a[i-1] + a[k-1] == a[j-1] + a[l-1]:
					print("YES")
					print(i,k,j,l)
					return
				elif a[i-1] + a[l-1] == a[j-1] + a[k-1]:
					print("YES")
					print(i,l,j,k)
					return

			if sz == 5:
				i,j,k,l,m = [idx + 1 for idx in list(dic[SUM])]
				print("YES")
				print(j,k,l,m)
				return 


	print("NO")

if __name__ == '__main__':
	main()