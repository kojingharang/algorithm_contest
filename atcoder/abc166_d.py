N=1000
vs = [v**5 for v in range(N)]
print(vs)

#for i in range(N):
#	print(i**5)

for i in range(len(vs)-1):
	print(abs(vs[i+1]-vs[i]))

#h = [ 0 for i in range(N) ]

#for i in range(len(vs)):
#	for j in range(len(vs)):
#		v = vs[i]-vs[j]
#		if 0<=v<N:
#			h[v]=(i, j)
#
#print(h)
