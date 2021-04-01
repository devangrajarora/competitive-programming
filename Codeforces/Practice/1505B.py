import math

n = int(input())
ans = n%9 if n%9 is not 0 else 9
print(ans)