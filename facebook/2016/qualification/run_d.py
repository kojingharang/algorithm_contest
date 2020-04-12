import sys
N = int(sys.argv[1])

files = ""
for i in range(N):
	print "./a.out {N} {i} < big.txt | tee d_out_{i}.txt &".format(**vars())
	files += " d_out_{i}.txt ".format(**vars())
print "wait"
print "cat {files} > d_out.txt".format(**vars())

