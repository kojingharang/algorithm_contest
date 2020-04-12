import sys
sys.setrecursionlimit(1000000)
 
K = input()
while K%2==0:
    K /= 2
while K%5==0:
    K /= 5
 
T = [[0]*10 for _ in range(10)]
for i in range(10):
    for j in range(10):
        T[i][i*j%10] = j
 
memo = [-1]*100000
def f(x):
    if x==0:
        return 0
    if memo[x]>=0:
        return memo[x]
    if memo[x]==-2:
        return 99999999
    memo[x] = -2
    ans = sum(map(int, str(x)))
    for i in range(10):
        #for j in range(10):
        #    if (j*K+x)%10==i:
        #        ans = min(ans, i+f((j*K+x)/10))
        ans = min(ans, i+f((T[K%10][(i-x)%10]*K+x)/10))
        print(x, i, ans)
    memo[x] = ans
    return ans
print f(K)

