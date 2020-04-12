import math
import random

def primes(x):
    if x < 2: return []
    primes = [i for i in range(x)]
    primes[1] = 0
    for prime in primes:
        if prime > math.sqrt(x): break
        if prime == 0: continue
        for non_prime in range(2 * prime, x, prime): primes[non_prime] = 0
    return [prime for prime in primes if prime != 0]

TT = 100
print(TT)
for T in range(TT):
	N = 10000
	prs = primes(N)
	random.shuffle(prs)
	cs = list(sorted(prs[:26]))
	M = dict([ (chr(ord("A")+i), cs[i]) for i in range(26) ])

	az = "".join([chr(ord("A")+i) for i in range(26)])
	for i in range(70):
		az += random.choice(az)
	print(N, len(az)-1)
	D = [M[c] for c in az]
	C = [ D[i]*D[i+1] for i in range(len(D)-1) ]
	print(" ".join(map(str, C)))

#	print(len(cs), cs)
#	print(M)
#	print(az)
