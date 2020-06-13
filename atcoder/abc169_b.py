while True:
	try:
		N=input()
	except:
		break
	a=list(map(int, input().split()))
	#print(a)
	ans=1
	for v in a:
		ans*=v
		if 1000000000000000000 < ans:
			ans = -1
			break
	if any([v==0 for v in a]):
		ans=0
	print(ans)
