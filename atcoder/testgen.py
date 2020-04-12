import sys
import random

w=500
h=500
#w=10
#h=10
print w, h

sx = random.randint(0, w-1)
sy = random.randint(0, h-1)
gx = random.randint(0, w-1)
gy = random.randint(0, h-1)

pr = sys.stdout.write
#for y in range(h):
#	for x in range(w):
#		if sx==x and sy==y:
#			pr("s")
#		elif gx==x and gy==y:
#			pr("g")
#		elif random.random() < 0.1:
#			pr("#")
#		else:
#			pr(str(random.randint(0, 9)))
#	print

sx=0
sy=0
gx=499
gy=499
for y in range(h):
	for x in range(w):
		if sx==x and sy==y:
			pr("s")
		elif gx==x and gy==y:
			pr("g")
		elif (y%2==1 and x<499) or (y>0 and y/2%2==1 and x==498) or (y>0 and y/2%2==0 and x==0):
			pr("9")
		else:
			pr("0")
	print


