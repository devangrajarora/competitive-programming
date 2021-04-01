tc, k = map(int,input().split())
MAXM = 100005
MOD = 1000000007
dp = [ 1 for _ in range(MAXM) ]

for i in range(k,MAXM):
	dp[i] = (dp[i-1] + dp[i-k]) % MOD
for i in range(1,MAXM):
	dp[i] += dp[i-1]

for i in range(tc):
	a,b = map(int,input().split())
	print((dp[b] - dp[a-1])%MOD)