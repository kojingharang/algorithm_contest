import random

N = 2*10**5
#N = 10
print(N)
A = [ random.randint(1, 10**6) for i in range(N) ]
print(" ".join(map(str, A)))
