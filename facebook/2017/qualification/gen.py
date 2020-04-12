import random

def cbig():
	T = 1000
	print(T)
	for t in range(T):
		H = 10000
		S = 10
		X = 20
		Y = 20
		Z = random.choice([10000, -10000])
		print(H, S)
		for s in range(S):
			print("%dd%d%+d " % (X, Y, Z), end="")
		print()

def crandom():
	T = 1000
	print(T)
	for t in range(T):
		H = random.randint(1, 10000)
		S = random.randint(2, 10)
		X = random.randint(1, 20)
		Y = random.choice([4, 6, 8, 10, 12, 20])
		Z = random.randint(-10000, 10000)
		print(H, S)
		for s in range(S):
			print("%dd%d%+d " % (X, Y, Z), end="")
		print()

def bbig():
	T = 500
	print(T)
	for t in range(T):
		N = 100
		W = 100
		print(N)
		for n in range(N):
			print(W)

def brandom():
	T = 500
	print(T)
	for t in range(T):
		N = random.randint(1, 100)
		print(N)
		while True:
			Ws = [ random.randint(1, 100) for n in range(N) ]
			if sum(Ws) >= 50:
				break;
		for W in Ws:
			print(W)

def aall():
	tcs = [ (P, X, Y) for P in range(101) for X in range(101) for Y in range(101) ]
	print(len(tcs))
	for P, X, Y in tcs:
		print(P, X, Y)

#crandom()
#brandom()
#bbig()
aall()

