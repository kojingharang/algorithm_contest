def solve_small(A,B,C):
	for i in range(B):
		if i==B-1:
			A = pow(A,A,C)
		else:
			A = A**A
	return A%C

for t in xrange(input()):
	A,B,C = map(int,raw_input().split())
	ans = solve_small(A,B,C)
	print "Case #%s: %s" % (t+1,ans)
