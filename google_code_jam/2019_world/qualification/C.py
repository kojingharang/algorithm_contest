import math

def gcd(a, b):
	return gcd(b,a%b) if b else a

TT = int(input())
#print(TT)

for T in range(TT):
	N, L = map(int, input().split(" "))
#	print(N, L)
	# [i] ... D[i]*D[i+1]
	C = list(map(int, input().split(" ")))
	prs = set()
	for i in range(len(C)):
		v = int(math.sqrt(C[i]))
		if v*v==C[i]:
			prs.add(v)
	for i in range(len(C)):
		for j in range(len(C)):
			if abs(i-j)<=1:
				g = gcd(C[i], C[j])
				if C[i]!=C[j] and g!=1:
					prs.add(g)
	o = set()
	for i in range(len(C)):
		for p in prs:
			if C[i] % p==0:
				v = C[i] // p
				if v not in prs:
					o.add(v)
	prs = prs | o
#	print(C)
	assert len(prs)==26, (len(prs), prs)

	D = [ set(prs) for i in range(L+1) ]
	while True:
		upd = False
		for i in range(L):
			for p in list(D[i]):
				if C[i] % p or C[i] // p not in D[i+1]:
					D[i].discard(p)
					upd = True
			for p in list(D[i+1]):
				if C[i] % p or C[i] // p not in D[i]:
					D[i+1].discard(p)
					upd = True
		if not upd:
			break
#	print(D)
#	print(prs)
#	print([len(D[i]) for i in range(len(D))])
	assert all([len(D[i])==1 for i in range(len(D))])
	D = [list(d)[0] for d in D]
	prs = list(sorted(list(prs)))
	M = dict([ (v, chr(ord("A")+i)) for i, v in enumerate(prs) ])
#	print(M)
	S = "".join([ M[D[i]] for i in range(L+1) ])
	print("Case #"+str(T+1)+": "+S)
