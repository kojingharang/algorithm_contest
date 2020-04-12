import random

def RI(a, b):
	return random.randint(a, b);

def abig():
	T = 100
	print(T)
	for t in range(T):
		N = 300
		M = 300
		print(N, M)
		for i in range(N):
			s = " ".join(map(str, [ 1000000 for j in range(M) ]))
			print(s)
		print()

def arandom():
	T = 100
	print(T)
	for t in range(T):
		N = random.randint(1, 300)
		M = random.randint(1, 300)
		print(N, M)
		for i in range(N):
			s = " ".join(map(str, [ random.randint(1, 1000000) for j in range(M) ]))
			print(s)
		print()

def bbig():
	T = 50
	print(T)
	for t in range(T):
		N = 50
		R = 1000000000
		print(N, R)
		for i in range(N):
			X = 1000000000-i
			Y = 1000000000-i
			print(X, Y)
		print()

def brandom():
	T = 50
	print(T)
	for t in range(T):
		N = RI(1, 50)
		R = RI(1, 1000000000)
		print(N, R)
		for i in range(N):
			X = RI(0, 1000000000)
			Y = RI(0, 1000000000)
			print(X, Y)
		print()

def cbig():
	T = 100
	print(T)
	for t in range(T):
		N = 100
		M = 5000
		K = 5000
		print(N, M, K)
		for i in range(M):
			A = N
			B = N-1
			G = 1000
			print(A, B, G)
		for i in range(K):
			S = N
			D = N-1
			print(S, D)
		print()

def crandom():
	T = 100
	print(T)
	for t in range(T):
		N = RI(2, 100)
		M = RI(1, 5000)
		K = RI(1, 5000)
		print(N, M, K)
		for i in range(M):
			A = RI(1, N)
			B = RI(1, N)
			G = RI(1, 1000)
			print(A, B, G)
		for i in range(K):
			S = RI(1, N)
			D = RI(1, N)
			print(S, D)
		print()

def dbig():
	T = 100
	print(T)
	for t in range(T):
		N = 2000
		M = 1000000000
		print(N, M)
		for i in range(N):
			R = 2000
			print(R)
		print()

def drandom():
	T = 100
	print(T)
	for t in range(T):
		N = RI(1, 2000)
		M = RI(1, 1000000000)
#		M = RI(1, 2000)
		print(N, M)
		for i in range(N):
			R = RI(1, 2000)
#			R = RI(1, 10)
			print(R)
		print()


#abig()
#arandom()
#bbig()
#brandom()
#cbig()
#crandom()
#dbig()
drandom()







