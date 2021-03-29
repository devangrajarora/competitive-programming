def findMaxIndex(index,a,curr):
   ans = -1
   index = 0
   for i in range(index,len(a)):
      if a[i]>curr:
         if ans == -1:
            ans = curr
            index = i
         else:
            ans = min(ans,a[i])
            index = i
   return index

def nextPermutation(nums):
   found = False
   i = len(nums)-2
   while i >=0:
      if nums[i] < nums[i+1]:
         found =True
         break
      i-=1
   if not found:
      return []
   else:
      m = findMaxIndex(i+1,nums,nums[i])
      nums[i],nums[m] = nums[m],nums[i]
      nums[i+1:] = nums[i+1:][::-1]
   return nums

def findCost(a):
   # print(f'fuck this {a}')
   a1 = list(a)
   n, ans = len(a1), 0
   for i in range(n-1):
      minIdx, minElem = i, a1[i]
      for j in range(i,n):
         if a1[j] < minElem:
            minElem, minIdx = a1[j], j
      a1[i:minIdx+1] = a1[i:minIdx+1][::-1]
      ans += (minIdx - i + 1)
   return ans

def solve(tc,n,c,a):
   ok, cost, cnt = False, 0, 0
   while cost != c and len(a) > 0:
      cost = findCost(a)
      # print(a,cost)
      if cost == c:
         ok = True
         break
      a = nextPermutation(a)
      # print(a)
      if len(a) == 0:
         break

   print(f'Case #{tc}: ', end="")
   if ok:
      for num in a:
         print(num, end=" ")
      print("")
   else:
      print("IMPOSSIBLE")

TC = int(input())
for tc in range(1,TC+1):
   n, c = map(int,input().split())
   a = [ num for num in range(1,n+1) ]
   solve(tc,n,c,a)

