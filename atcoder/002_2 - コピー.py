import sys
import datetime

N=int(sys.stdin.readline())
s = sys.stdin.readline().rstrip()
if N==1:
	print 1
	sys.exit(0)

#print s

tt = [ x+y for x in "ABXY" for y in "ABXY" ]
#print tt


ans = 10000
for L in tt:
	for R in tt:
		ans = min(ans, len(s.replace(L, "L").replace(R, "R")))

print ans
