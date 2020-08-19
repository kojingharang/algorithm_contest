N = int(input())
S = list(map(int, list(input())))

def pp(n):
	v = n
	pc = 0
	while 0<v:
		if v&1:
			pc+=1
		v = v//2
	return pc

def f(n):
#	print("f", n)
	if n==0:
		return 0
	pc = pp(n)
#	print("pc", pc, n%pc)
	return 1 + f(n % pc)

#print(N)
#print(s)

def s2i(s):
	v = 0
	for i in range(N):
		v = v*2 + int(s[i])
#	print(s, v)
	return v


ref = s2i(S)
refPC = pp(ref)

refm = [ ref % (refPC-1+i) for i in range(3) ]

print("ref", ref)
print("refPC", refPC)
print("refm", refm)

m = [ [0]*N for i in range(3) ]
for i in range(3):
	pc = refPC-1+i
	for j in range(N):
		if j==0:
			m[i][N-1-j] = 1 % pc
		else:
			m[i][N-1-j] = (m[i][N-1-(j-1)]*2)%pc

print("m", m)

for i in range(N):
	if S[i]:
		pc = refPC-1
		ans = 1+f((refm[0]-m[0][i]+pc)%pc)
	else:
		pc = refPC+1
		ans = 1+f((refm[2]+m[2][i]+pc)%pc)
	print(ans)
#	S[i] = 1-S[i]
#	print(f(s2i(S)))
#	S[i] = 1-S[i]

#print(f(7))

#N = 100000
#print(N)
#print("1" * N)
