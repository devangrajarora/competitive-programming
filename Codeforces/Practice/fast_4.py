import math

n,m = map(int, input().split())
fac = math.sqrt(3) / 2 
op1 = (n+n-1) *  int(m/fac)
op2 = (m+m-1) *  int(n/fac)
pizzas = max(op1, op2)
print(pizzas)