import sys

def f(y): # mon of Y/1
	N=y-2013
	return 12*N + N*(N+1)//2

while True:
	L = list(map(int, sys.stdin.readline().split()))
	if not len(L): break
	Y, M = L
	mon = (Y-2013)*12 + M-1;
	lo=2013
	hi=10**20
	while lo+1<hi:
		mid=(lo+hi)//2
		if f(mid) <= mon:
			lo=mid
		else:
			hi=mid
	m = mon-f(lo) + 1
	print(lo, m)
	



