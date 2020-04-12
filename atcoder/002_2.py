import sys
import datetime

y,m,d = map(int, sys.stdin.readline().split("/"))
d=datetime.date(y,m,d)
while True:
	if d.year % d.month==0 and (d.year / d.month) % d.day==0:
		print "%04d/%02d/%02d" % (d.year, d.month, d.day)
		sys.exit(0)
	d = d + datetime.timedelta(1)
